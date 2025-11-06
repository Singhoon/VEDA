#include <iostream>
#include <map>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>   

using namespace std;
namespace fs = filesystem;


vector<string> split(string s, const string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens; 
}

int main() {

    multimap<string, string> dictionary;

    ifstream inFile("wordcard.txt");
    if (!inFile) {
        cout << "wordcard.txt 파일을 찾을 수 없습니다." << endl;
        return 1; 
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        vector<string> cur_line = split(line, ",");

        if (cur_line.size() >= 2) {
            dictionary.insert({ cur_line[0], cur_line[1] });
        }
    }

    string insert;
    cin >> insert;

    auto it = dictionary.find(insert);
    if (it != dictionary.end()) cout << insert << " : " << it->second << endl;

    return 0;
}