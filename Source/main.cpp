#include <iostream>
#include <limits>
#include "ServiceSystem.h"
using namespace std;

int main() {
    ServiceSystem system;
    int choice = 0;
    do {
        cout << "\n===== HOME SERVICE BOOKING =====\n"
             << "1. Add Record\n2. Display Records\n3. Search Booking\n"
             << "4. Update Booking\n5. Delete Booking\n6. Book a Service\n"
             << "7. Report\n8. Save Data\n9. Exit\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        try {
            switch (choice) {
                case 1: system.addRecord(); break;
                case 2: system.displayRecords(); break;
                case 3: system.searchRecord(); break;
                case 4: system.updateRecord(); break;
                case 5: system.deleteRecord(); break;
                case 6: system.bookService(); break;
                case 7: system.showReport(); break;
                case 8: system.saveLoad(); break;
                case 9: system.saveLoad(); cout << "Thank you. Goodbye!\n"; break;
                default: cout << "Choose a number from 1 to 9.\n";
            }
        } catch (const exception& e) { cout << "Error: " << e.what() << endl; }
    } while (choice != 9);
    return 0;
}
