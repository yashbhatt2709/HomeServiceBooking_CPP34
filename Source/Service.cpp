#include <iostream>
#include "Service.h"
using namespace std;

Service::Service() : id(0), name(""), price(0) {}
Service::Service(int i, string n, double p) : id(i), name(n), price(p) {}
int Service::getId() const { return id; }
string Service::getName() const { return name; }
double Service::getPrice() const { return price; }
void Service::display() const {
    cout << id << ". " << name << " - Rs. " << price << endl;
}
