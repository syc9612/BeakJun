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

void enroll_nm_adr(){
    //sign in
    //https://m.blog.naver.com/sea5727/220978963342
    
    /*
    C++ 스타일의 파일 입출력을 위해 std::ofstream을 사용하도록 변경
    FILE* fp; //fp file pointer
    fp = fopen("./address_info.txt","wt");
    */

    std::ofstream fp("./address_info.txt");


    if (!fp.is_open()) {
        std::cerr << "파일을 열 수 없습니다 - 종료 \n";
        return;
    }
    
    std::string str_name;
    std::cout << "이름 입력: " <<std::endl;
    std::getline(std::cin, str_name); // 전체 입력을 받기 위해 getline 사용

    std::string str_address;
    std::cout << "주소 입력: " << std::endl;
    std::getline(std::cin, str_address); // 주소도 동일하게 입력 받음

    address_check(str_address);

    fp << str_name << std::endl;
    fp << str_address << std::endl;

    fp.close();
    std::cout << "Complete" << std::endl;
}



