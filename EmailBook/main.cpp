//#include "EmailBook.h"
#include "AddressBook.h"
#include <regex>

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
bool isValidEmail_regex(const std::string& email){
    const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(email, pattern);
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
            if(isValidEmail_regex(email)){
                addressBook.addContact(name, email);
            }
            else{
                std::cout << "it is wrong format.\n";
            }
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
            if(isValidEmail_regex(newEmail)){
                addressBook.updateContact(email, newName, newEmail);
            }
            else{ std::cout << "it is wrong format.\n";}
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