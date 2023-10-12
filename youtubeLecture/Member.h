#pragma once
#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class PlaveMember {
private:
    std::string name;
    std::string age;
    std::string position;

public:
    PlaveMember(std::string _name, std::string _age, std::string _position);
    std::string getName();
    std::string getAge();
    std::string getPosition();
};

#endif
