/*
Banking System Ver 0.1
Author : syc
Content : OOP base constructure by step
*/

#include <iostream>
#include <string>
#include <vector>


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


Account::Account(){}
Account::~Account(){}

void Account::showAll() const{

}
void Account::makeAccout(int id, std::string name, int cash){
    accounts.emplace_back(id, name, cash);

}

void Account::deposite(int id, int money){

}
void Account::withdraw(int id, int money){

}