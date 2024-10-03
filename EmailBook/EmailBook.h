#include <string>
#include <iostream>

//https://github.com/leejeong0495/AddressProject/blob/main/Address.cpp
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
    void delete_Address(); //hmmm?
    void updateAddress();
    void exportCSV();
};

EmailBook::EmailBook(){
    this->index_ = int(0);
    this->name_ = std::string(""); //초기화
    this->address_= std::string("");
}
EmailBook::~EmailBook(){

}

std::string EmailBook::getName() const{
    return this->name_;
}

void EmailBook::setName(std::string Book_Name){
    this->name_ = Book_Name;
}

std::string EmailBook::getAddress() const{
    return this->address_;
}

void EmailBook::setAddress(std::string Book_Address){
    this->address_ = Book_Address;
}
void EmailBook::readAddress(){
    std::cout << "귀하의 이름은 : " << this->name_ << std::endl;
	std::cout << "귀하의 이메일은 : " << this->address_ << std::endl;
}

void EmailBook::deleteAddress(){
    std::string delete_{" "};

    this->name_ = delete_;
    this->address_ = delete_;
}

void EmailBook::delete_Address(){
    std::string delete1{""};
    
    std::cout << "delete info successful" << std::endl;
}