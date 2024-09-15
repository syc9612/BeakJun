#include <iostream>
#include <fstream>
#include <string>

char enroll_nm_adr(char name, char address){
    //sign in
    std::string line;
    ifstream file("user_info.txt"); //make file and create
    
    if(file.is_open()){
        std::file << name << "\t";
        std::file << address << std::endl;;
    }
    else{
        std::cout << "error" << std::endl;
        return 1;
    }


    if(file.is_open()){
        while(getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
    }
    else{
        std::cout << "Unable to open file";
        return 1;
    }
    
    //duplicate check

}

void print(char trg_name){

}

