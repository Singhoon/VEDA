#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <chrono>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

class Player; 

class Computer {
private:
	int cnt = 0;
	string words[10000] = { "", };

	friend class Player;
	Player* players[10]; 
	bool player_slots_active[10] = { false, };

	bool check_player_word(int player_id, string player_word);
	void computer_respond();

public:
	string current_word = "";
	bool is_user_lost[10] = { false, };
	bool is_computer_lost = false;
	int total_active_players = 0;

	Computer();
	~Computer();

	void start_a_game() { cout << "게임을 시작하겠습니다." << endl; };
	void show_a_word();

	bool handle_turn(int player_id);
};

class Player {
public:
	int user_id;
	string my_word = "";

	Player(int user_id, Computer& computer);
	Player(); // 기본 생성자
	~Player() {}; 
	void write_a_word();
};

Computer::Computer() {
	ifstream inFile("words.txt");
	if (!inFile) {
		cout << "words.txt 파일을 찾을 수 없습니다." << endl;
		return;
	}
	string line;
	while (getline(inFile, line)) {
		if (line.empty()) continue;
		words[cnt] = line;
		cnt++;
		if (cnt == 10000) break;
	}
	cout << "총 " << cnt << "개의 단어를 로드했습니다." << endl;

	for (int i = 0; i < 10; ++i) {
		players[i] = nullptr;
		player_slots_active[i] = false;
		is_user_lost[i] = false;
	}
}

Computer::~Computer() {
	cout << "\n게임 종료. 컴퓨터 소멸자 호출." << endl;
	for (int i = 0; i < 10; ++i) {
		if (players[i] != nullptr) {
			delete players[i]; 
			players[i] = nullptr;
		}
	}
}

void Computer::show_a_word() {
	if (cnt == 0) {
		cout << "오류: 로드된 단어가 없습니다." << endl;
		current_word = "오류";
		return;
	}
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<int> dist(0, cnt - 1);
	int rand_num = dist(gen);
	current_word = words[rand_num];
	cout << "현재 컴퓨터가 고른 단어 : " << current_word << endl;
}

bool Computer::check_player_word(int player_id, string player_word) {
	char player_start_char = player_word[0];
	char computer_end_char = current_word[current_word.length() - 1];

	if (player_start_char != computer_end_char) {
		cout << "플레이어 " << player_id << "의 패배입니다 (단어: " << player_word << ")" << endl;
		is_user_lost[player_id] = true;
		total_active_players--;
		return false;
	}
	current_word = player_word;
	return true;
}

void Computer::computer_respond() {
	if (cnt == 0) {
		is_computer_lost = true;
		return;
	}
	char player_end_char = current_word[current_word.length() - 1];

	int attempts = 0;
	int max_attempts = (cnt == 0) ? 1 : cnt * 5;

	while (true) {
		if (attempts > max_attempts) {
			is_computer_lost = true;
			cout << "컴퓨터가 '" << player_end_char << "'(으)로 시작하는 단어를 찾지 못했습니다!" << endl;
			cout << "컴퓨터의 패배!" << endl;
			return;
		}

		random_device rd;
		mt19937_64 gen(rd());
		uniform_int_distribution<int> dist(0, cnt - 1);
		int rand_num = dist(gen);
		string cur = words[rand_num];

		if (cur[0] == player_end_char) {
			current_word = cur;
			break;
		}
		attempts++;
	}
	cout << "현재 컴퓨터가 고른 단어 : " << current_word << endl;
}

bool Computer::handle_turn(int player_id) {
	if (!player_slots_active[player_id] || is_user_lost[player_id])
	{
		return false; 
	}

	cout << "\n--- 플레이어 " << player_id << "의 턴 ---" << endl;

	players[player_id]->write_a_word();
	string word = players[player_id]->my_word;

	bool player_is_safe = check_player_word(player_id, word);

	if (player_is_safe) {
		computer_respond();
	}
	return true; 
}


Player::Player() : user_id(-1) {} 

Player::Player(int user_id, Computer& computer) {
	if (user_id < 0 || user_id >= 10) {
		cout << "유저 번호 " << user_id << "는 유효하지 않습니다 (0-9)." << endl;
		this->user_id = -1;
		return;
	}

	if (computer.player_slots_active[user_id]) {
		cout << "이미 해당 번호 유저(" << user_id << ")가 있습니다. 배치를 실패했습니다." << endl;
		this->user_id = -1;
	}
	else {
		this->user_id = user_id;
		
		computer.players[user_id] = new Player(); 
		computer.players[user_id]->user_id = user_id; 
		computer.player_slots_active[user_id] = true;
		computer.total_active_players++; 3;
		cout << "유저 " << user_id << "가 게임에 참가했습니다." << endl;
	}
}

void Player::write_a_word() {
	cout << "단어를 입력하세요 : ";
	string str;
	cin >> str;
	my_word = str;
}



int main() {
	Computer computer;

	
	Player player1_registrar(0, computer); // 0번 유저로 등록 시도
	Player player2_registrar(1, computer); // 1번 유저로 등록 시도
	Player player3_registrar(0, computer); // 0번 유저 등록 시도 -> 실패함

	if (computer.total_active_players == 0) {
		cout << "게임 참가자가 없어 종료합니다." << endl;
		return 1;
	}

	computer.start_a_game();
	computer.show_a_word();

	if (computer.current_word == "오류") return 1;

	int turn_counter = 0;
	while (computer.total_active_players > 0 && !computer.is_computer_lost) {

		int current_player_id = turn_counter % 10;

		computer.handle_turn(current_player_id);

		turn_counter++;

	}

	if (computer.is_computer_lost) {
		cout << "\n최종 결과: 플레이어들의 승리!" << endl;
	}
	else if (computer.total_active_players == 0) {
		cout << "\n최종 결과: 모든 플레이어가 패배했습니다. 컴퓨터 승리!" << endl;
	}

	return 0; 
}