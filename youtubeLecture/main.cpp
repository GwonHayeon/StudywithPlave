#include <iostream>
#include <fstream>
#include <string>
#include "funtionZip.h"
#include <list>
#include "memberClass.cpp"
#include <algorithm> 
using namespace std;

void writeFile(list<PlaveMember>& l) {
	ofstream file("Plave.txt", ios::app); //example ������ ����. ������ ����

	if (file.is_open()) {
		//�����ü ����
//		list<PlaveMember> memberList;

		cout << "Name? ";
		string name;
		cin >> name;

		cout << "Age? ";
		string age;
		cin >> age;

		cout << "Position? ";
		string position;
		cin >> position;

		//�Է¹��� ������ �޸��忡 �Է��Ѵ�
		file << name << endl;
		file << age << endl;
		file << position << "\n" << endl;
		file.close();

		//�����ü�� ����
		PlaveMember member = PlaveMember(name, age, position);
		//�������Ʈ�� ��ü����
		l.push_back(member);

		cout << "add meber : " << member.getName();
	}
	else {
		cout << "Unable to open file";
	}
}

void printMember(list<PlaveMember> l) { //����Ʈ�� ����ϴ� ����
	list<PlaveMember>::iterator it;
	for (PlaveMember& member : l) {
		cout << member.getAge() <<"�� " << member.getPosition() << "��� " << member.getName() << "\n";
	}
}

//�˻� ����Ʈ

void readData(list<PlaveMember>& plaveList) {
	string line;
	ifstream file("Plave.txt"); //example ������ ����. ������ ����
	if (file.is_open()) {
		while (file) {
			string name;
			getline(file, name);
			string age;
			getline(file, age);
			string position;
			getline(file, position);
			string none;
			getline(file,none);
			PlaveMember plaveMember = PlaveMember(name, age, position);
			if (!name.empty()) {
				plaveList.push_back(plaveMember);
			}
		}
		//printMember(plaveList);
		file.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void printName(list<PlaveMember> plaveList)
{
	cin.ignore(100, '\n');
	string search;
	cout << "�̸� �Է� >> ";
	getline(cin, search);
	list<PlaveMember> l;
	//list<PlaveMember>::iterator it;
	for (PlaveMember member : plaveList) {
		if (member.getName() == search)
		{
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	printMember(l);
}

void printAge(list<PlaveMember> plaveList)
{
	cin.ignore(100, '\n');
	string search;
	cout << "���� �Է� >> ";
	getline(cin, search);
	list<PlaveMember> l;
	for (PlaveMember member : plaveList) {
		if (member.getAge() == search)
		{
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	printMember(l);
}

void printPosition(list<PlaveMember> plaveList)
{
	cin.ignore(100, '\n');
	string search;
	cout << "Position �Է� >> ";
	getline(cin, search);
	list<PlaveMember> l;
	for (PlaveMember member : plaveList) {
		if (member.getPosition() == search)
		{
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	printMember(l);
}

void searchMenu(list<PlaveMember> plaveList) {
	printSearch();
	int choice2 = -1;
	cin >> choice2;
	switch (choice2) {
		case 1:
			printName(plaveList);
			break;
		case 2:
			printAge(plaveList);
			break;
		case 3:
			printPosition(plaveList);
			break;
		case 4:
			printMember(plaveList);
			break;
		default:
			break;
	}
}

void sortByName(list<PlaveMember>& l) {
	l.sort([](const PlaveMember& a, const PlaveMember& b) {
		return a.name < b.name;
	});
	printMember(l);
}

void sortByAge(list<PlaveMember>& l) {
	l.sort([](const PlaveMember& a, const PlaveMember& b) {
		return a.age < b.age;
		});
	printMember(l);
}


void sortByPosition(list<PlaveMember>& l) {
	l.sort([](const PlaveMember& a, const PlaveMember& b) {
		return a.position < b.position;
		});
	printMember(l);
}

void sortingMenu(list<PlaveMember> plaveList) {
	printSorting();
	int choice2 = -1;
	cin >> choice2;
	switch (choice2) {
	case 1:
		sortByName(plaveList);
		break;
	case 2:
		sortByAge(plaveList);
		break;
	case 3:
		sortByPosition(plaveList);
		break;
/*
	case 4:
		printMember(plaveList);
		break;
		*/
	default:
		break;
	}
}
int main() {
	list<PlaveMember> plaveList;
	int choice=-1;
	readData(plaveList);
	while (true) {
		printMenu();
		cin >> choice;
		switch (choice) {
			case 1: //�޸��忡 ����
				writeFile(plaveList);
				break;
			case 2: //�޸��� �о����
				readFile();
				break;
			case 3: //Ž��
				searchMenu(plaveList);
				break;
			case 4: //����
				sortingMenu(plaveList);
				break;
			case 5: //����
				return 0;
			default:
				break;
		}
	}

	return 0;
}