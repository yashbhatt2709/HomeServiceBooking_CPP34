#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Person.h"

class Customer : public Person {
public:
    Customer();
    Customer(int i, string n, string p);
    void display() const;
};
#endif
