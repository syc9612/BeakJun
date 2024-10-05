//#include "EmailBook.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "AddressBook.h"
void displayMenu(){
    std::cout << "\nAddress Book Menu:\n";
    std::cout << "1. Add Contact\n";
    std::cout << "2. Delete Contact\n";
    std::cout << "3. Update Contact by EmailAddress \n";
    std::cout << "4. Display All Contacts\n";
    std::cout << "5. Export to CSV\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    AddressBook addressBook("contacts.txt");

    while (true) {
        displayMenu();

        int choice;
        std::cin >> choice;

        std::string name, email, newName, newEmail, csvFilename;

        switch (choice) {
        case 1:
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter email: ";
            std::cin >> email;
            addressBook.addContact(name, email);
            break;

        case 2:
            std::cout << "Enter email to delete: ";
            std::cin >> email;
            addressBook.deleteContact(email);
            break;

        case 3:
            std::cout << "Enter current email: ";
            std::cin >> email;
            std::cout << "Enter new name: ";
            std::cin >> newName;
            std::cout << "Enter new email: ";
            std::cin >> newEmail;
            addressBook.updateContact(email, newName, newEmail);
            break;

        case 4:
            addressBook.displayContacts();
            break;

        case 5:
            std::cout << "Enter CSV filename: ";
            std::cin >> csvFilename;
            addressBook.exportToCSV(csvFilename);
            break;

        case 6:
            std::cout << "Exiting...\n";
            return 0;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}