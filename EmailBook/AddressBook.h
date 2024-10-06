#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact
{
    std::string name;
    std::string email;
};

std::ostream& operator<<(std::ostream& ostream, const Contact& contact)
{
    ostream << "[name=" <<contact.name << ", email=" << contact.email << "]";
    return ostream;
}

std::ofstream &operator<<(std::ofstream &ostream, const Contact &contact)
{
    ostream << contact.name << " " << contact.email << std::endl;
    return ostream;
}

class AddressBook
{
private:
    using contact_list_t = std::vector<Contact>;
    contact_list_t contacts; // vector가 동적인 처리가 편함.
    std::string filename;

    //캡슐화를 위해 필요함.
    //생각해보면 load나 save는 메인함수쪽에서 굳이 호출해야하는 이유가 없음.
    void loadFromFile()
    {
        std::ifstream infile(filename);
        if (infile.is_open())
        {
            Contact contact;
            while (infile >> contact.name >> contact.email)
            { 
                //infile >> contact.name >> contact.email의 반환값은 bool 타입
                contacts.push_back(contact);
            }
            infile.close();
        }
    }

    void saveToFile()
    {
        std::ofstream outfile(filename);
        if(outfile.is_open())
        {
            for(const auto& contact : contacts)
            { 
                //c++11 에서 도입된 기능 
                outfile << contact;
            }
            outfile.close();
        }
    }

    bool exists(const std::string& email)
    {
        auto found = std::find_if(
            contacts.begin(),
            contacts.end(),
            [&email](const Contact &c)
            { return c.email == email; });

        if (found != contacts.end())
        {
            return true;
        }

        return false;
    }
 
public:
    //생성자
    AddressBook(const std::string &file) 
        : filename(file)
    {
        loadFromFile();
    }

    //연락처 추가
    void addContact(const std::string& name, const std::string& email)
    {
        if(exists(email) == true)
        {
            std::cout << "ERROR: The e-mail address is not invalid. \n";
            return;
        }

        contacts.push_back({name, email});
        saveToFile();
        std::cout << "Contact " << contacts.back() << " added succefully.\n";
    }

    //연락처 삭제
    void deleteContact(const std::string &email)
    {
        auto it = std::remove_if(
            contacts.begin(), 
            contacts.end(), 
            [&email](const Contact &c) { return c.email == email; }
        );

        if (it != contacts.end())
        {
            contacts.erase(it, contacts.end());
            saveToFile();
            std::cout << "Contact " << *it << " deleted succesfully.\n";
        }
        else
        {
            std::cout << "ERROR: No Contact found with the provided email.\n";
        }

    }
    //연락처 수정
    void updateContact(const std::string &email, const std::string &newName, const std::string &newEmail)
    {
        auto it = std::find_if(
            contacts.begin(), 
            contacts.end(), 
            [&email](const Contact &c) { return c.email == email; }
        );

        if(it != contacts.end())
        {
            if(newEmail != email || exists(newEmail))
            {
                std::cout << "ERROR: the new email address is already registed.\n";
                return;
            }
            it->name = newName;
            it->email = newEmail;
            saveToFile();
            std::cout << "Contact " << *it << " update successfulyy.\n";
        }
        else
        {
            std::cout << "ERROR: No contact found with the provided email.\n";
        }
    }
    //연락처 조회
    void displayContacts() const
    {
        if(contacts.empty())
        {
            std::cout << "Address book is empty.\n";
            return;
        }

        std::cout << "Current Contacts:\n";
        for(const Contact &contact : contacts)
        {
            std::cout << "  "  << contact << "\n";
        }
    }
    //csv로 내보내기
    void exportToCSV(const std::string& csvFilename)
    {
        std::ofstream csvFile(csvFilename);

        if(csvFile.is_open()) 
        {
            csvFile << "Name,Email\n";
            for(const auto &contact : contacts)
            {
                csvFile << contact.name << "," << contact.email << "\n";
            }
            csvFile.close();
            std::cout << "Contacts exported to " << csvFilename << " successfully.\n";
        } 
        else 
        {
            std::cout << "Error: Could not open file for CSV export.\n";
        }
    }
    
};