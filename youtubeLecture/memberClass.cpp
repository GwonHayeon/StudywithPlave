#include <string>
using namespace std;
class Student {

public:
	string name;
	string studentId;
	string birthYear;
	string departmentName;
	string tel;
	Student(string _name, string _studentId, string _birthYear, string _departmentName, string _tel)
	{
		name = _name;
		studentId = _studentId;
		birthYear = _birthYear;
		departmentName = _departmentName;
		tel = _tel;
	};
	string getName() { return name; }
	string getStudentId() { return studentId; }
	string getBirthYear() { return birthYear; }
	string getDepartment() { return departmentName; }
	string getTel() { return tel; }
	string getAdmissionYear() { return studentId.substr(0,4); }
};