#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;

namespace fs = filesystem;

int main() {

	fs::create_directories("dir");

	ofstream outFile("dir/suseok.txt");
	outFile << "Hello, my file!" << endl;
	outFile.close();

	ifstream inFile("dir/suseok.txt");
	string line;
	while (getline(inFile, line)) cout << line << endl;
	inFile.close();

	fs::remove_all("dir");

	return 0;
}