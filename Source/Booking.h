#ifndef BOOKING_H
#define BOOKING_H
#include <string>
using namespace std;

class Booking {
private:
    int id;
    string customerName;
    string serviceName;
    string workerName;
    string date;
    double amount;
public:
    Booking();
    Booking(int i, string c, string s, string w, string d, double a);
    int getId() const;
    string getCustomerName() const;
    string getServiceName() const;
    string getWorkerName() const;
    string getDate() const;
    double getAmount() const;
    void setDate(string d);
    void display() const;
};
#endif
