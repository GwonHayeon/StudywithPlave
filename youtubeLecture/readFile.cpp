#include <iostream>
#include <fstream>
#include <string>
#include "funtionZip.h"
using namespace std;

void readFile() {
	string line;
	ifstream file("studentAge.txt"); //example ������ ����. ������ ����
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