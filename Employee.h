#pragma once
#include <iostream>
using namespace std;

class Employee {
    public:
        string name;
        string position;
        int age;

        Employee() {};

        Employee(string n, string p, int a) {
            name = n;
            position = p;
            age = a;
        }

        friend ostream& operator<< (ostream& os, const Employee& e) {
            os << "Name: " << e.name << " \t" << "Position: " << e.position << " \t" << "Age: " << e.age;
            return os;
        }
};