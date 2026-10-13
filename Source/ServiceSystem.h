#ifndef SERVICESYSTEM_H
#define SERVICESYSTEM_H
#include <vector>
#include "Customer.h"
#include "Worker.h"
#include "Service.h"
#include "Booking.h"
#include "FileManager.h"

class ServiceSystem {
private:
    Customer* customers;
    int customerCount;
    Worker* workers;
    int workerCount;
    Service* services;
    int serviceCount;
    std::vector<Booking> bookings;
    FileManager fileManager;
    int nextBookingId;
    void showServices() const;
    void showWorkers() const;
public:
    ServiceSystem();
    ~ServiceSystem();
    void addRecord();
    void displayRecords() const;
    void searchRecord() const;
    void updateRecord();
    void deleteRecord();
    void bookService();
    void showReport() const;
    void saveLoad();
};
#endif
