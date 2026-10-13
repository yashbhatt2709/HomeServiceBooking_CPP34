#include "Person.h"
Person::Person() : id(0), name(""), phone("") {}
Person::Person(int i, string n, string p) : id(i), name(n), phone(p) {}
Person::~Person() {}
int Person::getId() const { return id; }
