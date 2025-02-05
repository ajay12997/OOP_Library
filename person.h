#define PERSON_H
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int personID;

public:
    Person(string n, int id);
    virtual void showInfo() = 0;  // virtual function
};


