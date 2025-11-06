#include <iostream>
//#include <string>
#include <map>

using namespace std;
// c, c++, qt 세 과목이 있는데 멀티 키 안되고 동명이인 없음. 그 다음 찾는 학생의 시험점수와 평균점수를 출력. 없으면 없다고 함

struct Score {
	int c;
	int cplus;
	int qt;
};

int main() {

	map<string, Score> st;
	st.insert(make_pair("kim", Score{ 95,80,70 }));
	st.insert(make_pair("lee", Score{ 90,80,89 }));
	st.insert(make_pair("park", Score{ 88,57,78 }));
	st.insert(make_pair("na", Score{ 94,84,72 }));
	st.insert(make_pair("jeon", Score{ 91,73,63 }));

	string name;
	cout << "찾을 학생의 이름을 입력하세요 : ";
	cin >> name;

	auto it = st.find(name);
	if (it != st.end()) cout << it->second.c << ' ' << it->second.cplus << ' ' << it->second.qt << ' ' << ((it->second.c + it->second.cplus + it->second.qt) / 3) << endl;
	else cout << name << "의 정보를 찾을 수 없습니다." << endl;

	/*
	map<string, int> scores;
	
	scores.insert(make_pair("Bob", 85));
	scores.insert(make_pair("Jane", 90));
	scores.insert(make_pair("Tom", 70));

	cout << "scores의 크기 : " << scores.size() << endl;

	auto it = scores.find("Bob");
	if (it != scores.end()) cout << "Bob의 점수 : " << it->second << endl;
	else cout << "Bob의 점수는 없음" << endl;

	cout << endl;

	scores.erase("Bob");

	cout << "Bob 제거 후 scores 크기 : " << scores.size() << endl << endl;

	cout << "모든 원소 출력" << endl;

	for (const auto& pair : scores) cout << pair.first << " : " << pair.second << endl;
	*/
	return 0;
}