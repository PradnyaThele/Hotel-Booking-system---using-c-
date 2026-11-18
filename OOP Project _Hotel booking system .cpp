#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Room {
    int roomNumber;
    string type;
    double price;
    bool isBooked;
    string guestName;
};

class HotelSystem {
private:
    vector<Room> rooms;

public:
    HotelSystem() {
        // Initialize some sample rooms
        rooms = {
            {101, "Single", 50.0, false, ""},
            {102, "Single", 50.0, false, ""},
            {201, "Double", 85.0, false, ""},
            {202, "Double", 85.0, false, ""},
            {301, "Suite", 150.0, false, ""}
        };
    }

    void displayRooms() {
        cout << "\n Available & Booked Rooms \n";
        cout << "Room No\tType\t\tPrice\tStatus\t\tGuest\n";
        cout << "----------------------------------------------------\n";
        for (const auto& room : rooms) {
            cout << room.roomNumber << "\t" 
                 << room.type << "\t\t$" 
                 << room.price << "\t" 
                 << (room.isBooked ? "Booked" : "Available") << "\t\t"
                 << (room.isBooked ? room.guestName : "-") << "\n";
        }
        cout << "----------------------------------------------------\n";
    }

    void bookRoom() {
        int roomNum;
        cout << "\nEnter room number you want to book: ";
        cin >> roomNum;

        for (auto& room : rooms) {
            if (room.roomNumber == roomNum) {
                if (room.isBooked) {
                    cout << "Sorry, Room " << roomNum << " is already booked!\n";
                } else {
                    cout << "Enter guest name: ";
                    cin.ignore(); // Clear input buffer
                    getline(cin, room.guestName);
                    room.isBooked = true;
                    cout << "Success! Room " << roomNum << " has been booked for " << room.guestName << ".\n";
                }
                return;
            }
        }
        cout << "Invalid room number. Please try again.\n";
    }

    void checkoutRoom() {
        int roomNum;
        cout << "\nEnter room number to checkout: ";
        cin >> roomNum;

        for (auto& room : rooms) {
            if (room.roomNumber == roomNum) {
                if (!room.isBooked) {
                    cout << "Room " << roomNum << " is not currently booked.\n";
                } else {
                    cout << "Guest " << room.guestName << " checked out from Room " << roomNum << ".\n";
                    room.isBooked = false;
                    room.guestName = "";
                }
                return;
            }
        }
        cout << "Invalid room number. Please try again.\n";
    }
};

int main() {
    HotelSystem hotel;
    int choice;

    do {
        cout << "\n Hotel Room Booking System " << endl;
        cout << "1. View Rooms" << endl;
        cout << "2. Book a Room" << endl;
        cout << "3. Checkout Room" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2:
                hotel.bookRoom();
                break;
            case 3:
                hotel.checkoutRoom();
                break;
            case 4:
                cout << "Thank you for using the Hotel Booking System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
