#include <string>
using namespace std;
class PlaveMember {

public:
	string name;
	string age;
	string position;
	PlaveMember(string _name, string _age, string _position)
	{
		name = _name;
		age = _age;
		position = _position;
	};
	string getName() { return name; }
	string getAge() { return age; }
	string getPosition() { return position; }
};