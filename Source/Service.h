#ifndef SERVICE_H
#define SERVICE_H
#include <string>
using namespace std;

class Service {
private:
    int id;
    string name;
    double price;
public:
    Service();
    Service(int i, string n, double p);
    int getId() const;
    string getName() const;
    double getPrice() const;
    void display() const;
};
#endif
