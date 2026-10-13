#include <iostream>
#include "Booking.h"
using namespace std;

Booking::Booking() : id(0), amount(0) {}
Booking::Booking(int i, string c, string s, string w, string d, double a)
    : id(i), customerName(c), serviceName(s), workerName(w), date(d), amount(a) {}
int Booking::getId() const { return id; }
string Booking::getCustomerName() const { return customerName; }
string Booking::getServiceName() const { return serviceName; }
string Booking::getWorkerName() const { return workerName; }
string Booking::getDate() const { return date; }
double Booking::getAmount() const { return amount; }
void Booking::setDate(string d) { date = d; }
void Booking::display() const {
    cout << "Booking ID: " << id << " | Customer: " << customerName
         << " | Service: " << serviceName << " | Worker: " << workerName
         << " | Date: " << date << " | Amount: Rs. " << amount << endl;
}
