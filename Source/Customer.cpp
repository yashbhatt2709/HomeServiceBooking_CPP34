#include <iostream>
#include "Customer.h"
using namespace std;

Customer::Customer() : Person() {}
Customer::Customer(int i, string n, string p) : Person(i, n, p) {}
void Customer::display() const {
    cout << "Customer ID: " << id << ", Name: " << name << ", Phone: " << phone << endl;
}
