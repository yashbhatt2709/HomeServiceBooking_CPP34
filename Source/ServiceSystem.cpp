#include <iostream>
#include <limits>
#include <stdexcept>
#include "ServiceSystem.h"
using namespace std;

ServiceSystem::ServiceSystem() : customers(new Customer[20]), workers(new Worker[20]), services(new Service[20]), customerCount(0), workerCount(0), serviceCount(0), nextBookingId(1) {
    // Starter data keeps the first run easy to test.
    customers[customerCount++] = Customer(1, "Asha", "9876543210");
    workers[workerCount++] = Worker(1, "Ravi", "9876500001", "Plumbing");
    workers[workerCount++] = Worker(2, "Meena", "9876500002", "Electrical");
    services[serviceCount++] = Service(1, "Plumbing", 400);
    services[serviceCount++] = Service(2, "Electrical Repair", 600);
    services[serviceCount++] = Service(3, "Home Cleaning", 500);
    try {
        fileManager.loadBookings(bookings);
        for (size_t i = 0; i < bookings.size(); ++i)
            if (bookings[i].getId() >= nextBookingId) nextBookingId = bookings[i].getId() + 1;
    } catch (const exception& e) { cerr << e.what() << endl; }
}
ServiceSystem::~ServiceSystem() {
    delete[] customers;
    delete[] workers;
    delete[] services;
}

void ServiceSystem::showServices() const {
    cout << "\nAvailable services:\n";
    for (int i = 0; i < serviceCount; ++i) services[i].display();
}
void ServiceSystem::showWorkers() const {
    cout << "\nAvailable workers:\n";
    for (int i = 0; i < workerCount; ++i) workers[i].display();
}
void ServiceSystem::addRecord() {
    cout << "\n1. Add customer  2. Add worker\nChoice: ";
    int choice; cin >> choice;
    if (choice == 1 && customerCount < 20) {
        int id = customerCount ? customers[customerCount-1].getId() + 1 : 1;
        string name, phone;
        cout << "Name (one word): "; cin >> name;
        cout << "Phone: "; cin >> phone;
        if (phone.length() < 10) { cout << "Phone must have at least 10 digits.\n"; return; }
        customers[customerCount++] = Customer(id, name, phone);
        cout << "Customer added.\n";
    } else if (choice == 2 && workerCount < 20) {
        int id = workerCount ? workers[workerCount-1].getId() + 1 : 1;
        string name, phone, skill;
        cout << "Name (one word): "; cin >> name;
        cout << "Phone: "; cin >> phone;
        cout << "Skill (one word): "; cin >> skill;
        if (phone.length() < 10) { cout << "Phone must have at least 10 digits.\n"; return; }
        workers[workerCount++] = Worker(id, name, phone, skill);
        cout << "Worker added.\n";
    } else cout << "Invalid choice or storage is full.\n";
}
void ServiceSystem::displayRecords() const {
    cout << "\n--- Customers (runtime polymorphism example) ---\n";
    for (int i = 0; i < customerCount; ++i) {
        const Person* person = &customers[i];
        person->display();
    }
    cout << "\n--- Workers ---\n";
    for (int i = 0; i < workerCount; ++i) workers[i].display();
    showServices();
    cout << "\n--- Bookings ---\n";
    if (bookings.empty()) cout << "No bookings yet.\n";
    for (size_t i = 0; i < bookings.size(); ++i) bookings[i].display();
}
void ServiceSystem::searchRecord() const {
    int id; cout << "Enter booking ID: "; cin >> id;
    for (size_t i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getId() == id) { bookings[i].display(); return; }
    }
    cout << "Booking not found.\n";
}
void ServiceSystem::updateRecord() {
    int id; cout << "Enter booking ID to update: "; cin >> id;
    for (size_t i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getId() == id) {
            string date; cout << "Enter new date (DD-MM-YYYY): "; cin >> date;
            bookings[i].setDate(date);
            saveLoad();
            cout << "Booking updated.\n"; return;
        }
    }
    cout << "Booking not found.\n";
}
void ServiceSystem::deleteRecord() {
    int id; cout << "Enter booking ID to delete: "; cin >> id;
    for (size_t i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getId() == id) {
            bookings.erase(bookings.begin() + i);
            saveLoad();
            cout << "Booking deleted.\n"; return;
        }
    }
    cout << "Booking not found.\n";
}
void ServiceSystem::bookService() {
    if (customerCount == 0 || workerCount == 0 || serviceCount == 0) {
        cout << "Customer, worker, or service list is empty.\n"; return;
    }
    showServices();
    int serviceId; cout << "Choose service ID: "; cin >> serviceId;
    int serviceIndex = -1;
    for (int i = 0; i < serviceCount; ++i)
        if (services[i].getId() == serviceId) serviceIndex = i;
    if (serviceIndex == -1) { cout << "Invalid service ID.\n"; return; }

    cout << "\nCustomers:\n";
    for (int i = 0; i < customerCount; ++i) customers[i].display();
    int customerId; cout << "Choose customer ID: "; cin >> customerId;
    int customerIndex = -1;
    for (int i = 0; i < customerCount; ++i)
        if (customers[i].getId() == customerId) customerIndex = i;
    if (customerIndex == -1) { cout << "Invalid customer ID.\n"; return; }

    showWorkers();
    int workerId; cout << "Choose worker ID: "; cin >> workerId;
    int workerIndex = -1;
    for (int i = 0; i < workerCount; ++i)
        if (workers[i].getId() == workerId) workerIndex = i;
    if (workerIndex == -1) { cout << "Invalid worker ID.\n"; return; }

    string date; cout << "Booking date (DD-MM-YYYY): "; cin >> date;
    try {
        bookings.push_back(Booking(nextBookingId++, "Customer#" + to_string(customerId),
            services[serviceIndex].getName(), workers[workerIndex].getName(),
            date, services[serviceIndex].getPrice()));
        saveLoad();
        cout << "Booking successful. Your booking ID is " << bookings.back().getId() << ".\n";
    } catch (const exception& e) { cout << "Error: " << e.what() << endl; }
}
void ServiceSystem::showReport() const {
    double total = 0;
    cout << "\n--- Booking Report ---\n";
    cout << "Total bookings: " << bookings.size() << endl;
    for (size_t i = 0; i < bookings.size(); ++i) total += bookings[i].getAmount();
    cout << "Total booking value: Rs. " << total << endl;
}
void ServiceSystem::saveLoad() {
    try { fileManager.saveBookings(bookings); cout << "Data saved.\n"; }
    catch (const exception& e) { cout << "File error: " << e.what() << endl; }
}
