#include <iostream>
#include <fstream>
#include <string>

std::string address_check(std::string address){
    //if @ is not existed, error
    std::cout << address.find("@");
    if(address.find("@") == std::string::npos){
        std::cout <<"no @ in Email."<<std::endl;
    }
    else{
        std::cout <<"check done" << std::endl;
    }
}

char enroll_nm_adr(){
    //sign in
    //https://m.blog.naver.com/sea5727/220978963342
    
    std::fstream dataFile;
    std::string buffer;

    dataFile.open("user_info.txt", std::ios::out);
    dataFile << "new word in file" << std::endl;
    dataFile.write("12345",5);
    dataFile.close();
    dataFile.open("user_info.txt", std::ios::in);

    getline(dataFile, buffer);
    std::cout << buffer << std::endl;
    char charbuff[10] = {0}; //initialize
    dataFile.read(charbuff,5);
    std::cout<<charbuff<<std::endl;
    dataFile.close();

    //duplicate check

}

void print(char trg_name){
    //print all
    if(trg_name == NULL){}

    //print target
    else{

    }
}

