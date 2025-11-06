#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;
// 원소가 많은 경우에는 binary_search가 find보다 더 빠르다(이미 정렬됐다고 하는 가정에서)
bool compare_pairs(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main() {
	vector<pair<int, string>> pairs = {
		{5, "apple"},
		{2, "orange"},
		{5, "banana"},
		{3, "grape"}
	};

	stable_sort(pairs.begin(), pairs.end(), compare_pairs);
	
	for (vector<pair<int, string>>::iterator it = pairs.begin(); it != pairs.end(); it++) {
		const pair<int, string>& pair = *it;
		cout << pair.first << ": " << pair.second << endl;
	}

	int target;
	cin >> target;

	// 1. 찾고자 하는 int 값으로 'dummy' pair를 만듭니다.
	//    string 부분은 ""(빈 문자열)처럼 아무거나 넣어도 상관없습니다.
	//    compare_pairs 함수는 .first만 보기 때문입니다.
	pair<int, string> target_pair = { target, "" };

	// 2. binary_search에 'dummy pair'와 '비교 함수'를 함께 전달합니다.
	bool found = binary_search(pairs.begin(), pairs.end(), target_pair, compare_pairs);

	if (found) cout << "찾았습니다." << endl;
	else cout << "못 찾았습니다." << endl; // <-- 못 찾았을 때도 알려주는 것이 좋습니다.
}

