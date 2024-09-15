#include <iostream>
#include <fstream>
#include <string>

std::string address_check(std::string address){
    //if @ is not existed, error
    std::cout << address.find("@");
    if(addess.find("@") == string::npos){
        std::cout <<"no @ in Email."<<std::endl;
    }
    else{
        std::cout <<"check done" << std::endl;
    }
}

char enroll_nm_adr(char name, char address){
    //sign in
    //https://m.blog.naver.com/sea5727/220978963342
    
    std::fsteram dataFile;
    std::string buffer;

    dataFile.open("user_info.txt", ios::out);
    std::dataFile << "new word in file" << std::endl;
    dataFile.write("12345",5);
    dataFile.close();
    dataFile.open("user_info.txt", ios::in);

    getline(dataFile, buffer);
    std::cout << vuffer << std::endl;
    char charbuff[10] = {0}; //initialize
    dataFile.read(charbuff,5);
    std::cout<<charbuff<<std::endl;
    dataFile.close();

    //duplicate check

}

void print(char trg_name){
    //print all
    if(tar_name == NULL)

    //print target
    else(

    )
}

