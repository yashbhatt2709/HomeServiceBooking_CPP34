#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <vector>
#include "Booking.h"

class FileManager {
public:
    void saveBookings(const std::vector<Booking>& bookings) const;
    void loadBookings(std::vector<Booking>& bookings) const;
};
#endif
