#include <fstream>
#include <iostream>
#include <sstream>
#include "FileManager.h"
using namespace std;

void FileManager::saveBookings(const vector<Booking>& bookings) const {
    ofstream file("Data/bookings.txt");
    if (!file) throw runtime_error("Could not open Data/bookings.txt for writing.");
    for (size_t i = 0; i < bookings.size(); ++i) {
        file << bookings[i].getId() << '|'
             << bookings[i].getCustomerName() << '|'
             << bookings[i].getServiceName() << '|'
             << bookings[i].getWorkerName() << '|'
             << bookings[i].getDate() << '|'
             << bookings[i].getAmount() << '\n';
    }
}
void FileManager::loadBookings(vector<Booking>& bookings) const {
    ifstream file("Data/bookings.txt");
    if (!file) return; // First run: the file may not exist yet.
    bookings.clear();
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idText, customer, service, worker, date, amountText;
        if (getline(ss, idText, '|') && getline(ss, customer, '|') &&
            getline(ss, service, '|') && getline(ss, worker, '|') &&
            getline(ss, date, '|') && getline(ss, amountText)) {
            try {
                bookings.push_back(Booking(stoi(idText), customer, service, worker,
                                           date, stod(amountText)));
            } catch (...) {
                cerr << "Skipped an invalid line in bookings.txt." << endl;
            }
        }
    }
}
