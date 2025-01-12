/*
Banking System Ver 0.1
Author : syc
Content : OOP base constructure by step
*/

#include <iostream>
#include <string>
#include <vector>

/* 
class Account {
    private:
        int id=0;
        int cash=0;
        std::string name;

        std::vector<Account> accounts;

    public:
        //Account(const std::string& name, int cash) : name(name), cash(cash){}
        Account();
        ~Account();

        void showAll() const;
        void deposite(int _id, int money);
        void withdraw(int _id, int money);

        void makeAccout(int id, std::string name, int cash);

        void print(){
            std::cout << "id: " << id  << std::endl;
        }
};

void Account::showAll() const{

}
void Account::makeAccout(int id, std::string name, int cash){
    accounts.emplace_back(id, name, cash);

}

void Account::deposite(int id, int money){

}
void Account::withdraw(int id, int money){

}
*/



// Account 클래스 정의
class Account {
public:
    // 생성자
    Account(const std::string& accID, double cash, const std::string& name);

    // Getter 메서드
    std::string getAccountID() const;
    double getCash() const;
    std::string getName() const;

    // Setter 메서드
    void deposit(double amount);
    void withdraw(double amount);

    // 출력 메서드
    void display() const;

private:
    std::string accID;
    double cash;
    std::string name;
};

// Account 클래스 메서드 정의
Account::Account(const std::string& accID, double cash, const std::string& name)
    : accID(accID), cash(cash), name(name) {
    if (cash < 0) {
        throw std::invalid_argument("Initial cash cannot be negative.");
    }
}

std::string Account::getAccountID() const {
    return accID;
}

double Account::getCash() const {
    return cash;
}

std::string Account::getName() const {
    return name;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        cash += amount;
    } else {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= cash) {
        cash -= amount;
    } else {
        throw std::invalid_argument("Invalid withdrawal amount.");
    }
}

void Account::display() const {
    std::cout << "Account ID: " << accID << "\n"
              << "Name: " << name << "\n"
              << "Cash: $" << cash << "\n";
}

// AccountManager 클래스 정의
class AccountManager {
public:
    void addAccount(const std::string& accID, double cash, const std::string& name);
    void removeAccount(const std::string& accID);
    void displayAccounts() const;

private:
    std::vector<Account> accounts;

    int findAccountIndex(const std::string& accID) const;
};

// AccountManager 메서드 정의
void AccountManager::addAccount(const std::string& accID, double cash, const std::string& name) {
    if (findAccountIndex(accID) != -1) {
        throw std::invalid_argument("Account ID already exists.");
    }
    accounts.emplace_back(accID, cash, name);
}

void AccountManager::removeAccount(const std::string& accID) {
    int index = findAccountIndex(accID);
    if (index == -1) {
        throw std::invalid_argument("Account ID not found.");
    }
    accounts.erase(accounts.begin() + index);
}

void AccountManager::displayAccounts() const {
    if (accounts.empty()) {
        std::cout << "No accounts available.\n";
        return;
    }
    for (const auto& account : accounts) {
        account.display();
        std::cout << "-------------------------\n";
    }
}

int AccountManager::findAccountIndex(const std::string& accID) const {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountID() == accID) {
            return static_cast<int>(i);
        }
    }
    return -1;
}
