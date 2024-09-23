#include <string>
#include <iostream>

class EmailBook{
    private:
    int index_;
    std::string name_, address_;

    public:
    EmailBook();
    ~EmailBook();

    std::string getName() const;
    void setName(std::string name);

    std::string getAddress() const;
    void setAddress(std::string address);

    void readAddress();
    void deleteAddress();
    void updateAddress();
}
EmailBook::EmailBook(){
    this->index_ = int(0);
    this->name_ = std::string(""); //초기화
    this->address_= std::string("");
}
Emai
lBook::~EmailBook(){

}

std::string EmailBook::getName() const{
    return this->address_;
}
void EmailBook::setName(std::string address){
    return 
}