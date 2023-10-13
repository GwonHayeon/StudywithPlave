#include <iostream>
#include <fstream>
#include <string>
#include "funtionZip.h"
#include <list>
#include "memberClass.cpp"
#include <algorithm> 
using namespace std;
int sortOption = 1; //default sortOption is Name

void doInsertion(list<Student>& l) {
	ofstream file("file1.txt", ios::app); //open file1.txt. if not, then generate
	if (file.is_open()) {
		//generate member obj
		string name;
		cin.ignore(100, '\n');
		do {
			cout << "Name ? ";
			getline(cin, name);
		} while (name.empty());


		//studentId can't same and not empty
		string studentId;
		int isExist=-1;
		do {
			cout << "Student ID (10 digits) ? ";
			getline(cin, studentId);
			isExist = 1;
			if (!studentId.empty()) { 
				for (Student& member : l) {	if (member.getStudentId() == studentId)	{isExist = 0;} }
				if (isExist == 0) { cout << "Error : already inserted" << endl; }
			}
			else { isExist = -1; }
		} while (isExist<1);
		
		cout << "Birth Year (4 digits) ? ";
		string birthYear;
		cin >> birthYear;

		cout << "Department ? ";
		cin.ignore(100, '\n');
		string departmentName;
		getline(cin, departmentName);

		cout << "Tel ? ";
		string tel;
		getline(cin, tel);
		
		//write input to in text file
		file << name << endl;
		file << studentId << endl;
		file << birthYear << endl;
		file << departmentName << endl;
		file << tel << "\n" << endl;
		file.close();

		//save Student obj
		Student member = Student(name, studentId, birthYear, departmentName, tel);
		//save obj to list
		l.push_back(member);
	}
	else {
		cout << "Unable to open file" << endl;
	}
}

void printMember(list<Student> l) { 
	//print Student by sortOption
	l.sort([](Student& a, Student& b) {
		switch (sortOption) {
		case 1: //name
			return a.getName() < b.getName();
		case 2: //id
			return a.getStudentId() < b.getStudentId();
		case 3: //Admission year
			return a.getAdmissionYear() < b.getAdmissionYear();
		case 4: //Department
			return a.getDepartment() < b.getDepartment();
		defualt:
			return a.getName() < b.getName();
		}
		});
	cout << "Name\t       " << "StudentID " << "Dept   \t\t" << "Birth Year " << "Tel" << "\n";
	for (Student& member : l) {
		cout << member.getName() << "  " << member.getStudentId() << " " << member.getDepartment() << "\t      " << member.getBirthYear() << " " << member.getTel() << "\n";
	}
}
void readData(list<Student>& studentList) {
	string line;
	ifstream file("file1.txt"); 	//open txt file. if not, generate
	if (file.is_open()) {
		while (file) {
			string name;
			getline(file, name);
			string studentId;
			getline(file, studentId);
			string birthYear;
			getline(file, birthYear);
			string departmentName;
			getline(file, departmentName);
			string tel;
			getline(file, tel);
			string none;
			getline(file,none);
			Student studentMember = Student(name, studentId, birthYear, departmentName, tel);
			if (!name.empty() || !studentId.empty()) {
				studentList.push_back(studentMember);
			}
		}
		file.close();
	} else {
		cout << "Unable to open file";
	}
}

void printName(list<Student> studentList)
{
	cin.ignore(100, '\n');
	string search;
	cout << "Name? ";
	getline(cin, search);
	list<Student> l;
	for (Student member : studentList) {
		if (member.getName().find(search) != string::npos)
		{
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	else { printMember(l); }
}

void printStudentId(list<Student> studentList)
{
	cin.ignore(100, '\n');
	string search;
	cout << "Student ID? ";
	getline(cin, search);
	list<Student> l;
	for (Student member : studentList) {
		if (member.getStudentId() == search)
		{
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	else {	printMember(l); }
}

void printAdmissionYear(list<Student> studentList)
{
	cin.ignore(100, '\n');
	string search;
	cout << "Admission Year? ";
	getline(cin, search);
	list<Student> l;
	for (Student member : studentList) {
		if (member.getAdmissionYear() == search)
		{
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	else{	printMember(l);	}
}

void printDepartment(list < Student> studentList) {
	cout << "Department name keyword? ";
	string search;
	cin >> search;
	list<Student> l;
	for (Student member : studentList) {
		if (member.getDepartment().find(search) != string::npos) {
			l.push_back(member);
		}
	}
	if (l.size() == 0) { cout << "No such Member" << endl; }
	else { printMember(l); }

}

void searchMenu(list<Student> studentList) {
	printSearch();
	int choice2 = -1;
	cin >> choice2;
	switch (choice2) {
		case 1:
			printName(studentList);
			break;
		case 2:
			printStudentId(studentList);
			break;
		case 3:
			printAdmissionYear(studentList);
			break;
		case 4:
			printDepartment(studentList);
			break;
		case 5:
			printMember(studentList);
			break;
		default:
			break;
	}
}

void sortingMenu(list<Student> studentList) {
	printSorting();
	int chooseSort = -1;
	cin >> chooseSort;
	sortOption = chooseSort;
	printMember(studentList);
}

int main() {
	list<Student> studentList;
	int choice=-1;
	readData(studentList);
	while (true) {
		printMenu();
		cin >> choice;
		switch (choice) {
			case 1: //insertion
				doInsertion(studentList);
				break;
			case 2: //search
				searchMenu(studentList);
				break;
			case 3: //sort
				sortingMenu(studentList);
				break;
			case 4: //exit
				return 0;
			default:
				break;
		}
	}

	return 0;
}