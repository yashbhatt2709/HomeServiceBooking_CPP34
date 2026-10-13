#include <iostream>
#include "Worker.h"
using namespace std;

Worker::Worker() : Person(), skill("") {}
Worker::Worker(int i, string n, string p, string s) : Person(i, n, p), skill(s) {}
void Worker::display() const {
    cout << "Worker ID: " << id << ", Name: " << name << ", Phone: " << phone
         << ", Skill: " << skill << endl;
}
string Worker::getName() const { return name; }
int Worker::getId() const { return id; }
