#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string phone;
public:
    Person();
    Person(int i, string n, string p);
    virtual ~Person();
    int getId() const;
    virtual void display() const = 0;
};
#endif
