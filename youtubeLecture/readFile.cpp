#include <iostream>
#include <fstream>
#include <string>
#include "funtionZip.h"
using namespace std;

void readFile() {
	string line;
	ifstream file("studentAge.txt"); //example 파일을 연다. 없으면 생성
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}