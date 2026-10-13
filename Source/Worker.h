#ifndef WORKER_H
#define WORKER_H
#include "Person.h"

class Worker : public Person {
private:
    string skill;
public:
    Worker();
    Worker(int i, string n, string p, string s);
    void display() const;
    string getName() const;
    int getId() const;
};
#endif
