#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

bool address_check(std::string address){
    //if @ is not existed, error
    if(address.find("@") == std::string::npos){ //정규표현식으로 변경하여 고민해볼것.
        std::cout <<"it is nor E-mail format. please check one more"<<std::endl;
        return false;
    }

    std::cout <<"check done" << std::endl;
    return true;
}

void enroll_nm_adr(){
    //sign in
    //https://m.blog.naver.com/sea5727/220978963342
    
    /*
    C++ 스타일의 파일 입출력을 위해 std::ofstream을 사용하도록 변경
    FILE* fp; //fp file pointer
    fp = fopen("./address_info.txt","wt");
    */

    std::ofstream fp("./address_info.txt",std::ios::app);


    if (!fp.is_open()) {
        std::cerr << "can not open the file \n";
        return;
    }
    
    std::string str_name;
    std::cout << "Enter Name: " <<std::endl;
    std::getline(std::cin, str_name); // 전체 입력을 받기 위해 getline 사용


    std::string str_address;
    std::cout << "Enter Address: " << std::endl;
    std::getline(std::cin, str_address); // 주소도 동일하게 입력 받음

    bool ret = address_check(str_address); //정합성 체크를 해야하는데 여기서 다시 돌릴 아이디어가 안떠오름
    if(ret == false)
    {
        std::cout << "failed." << std::endl;
        fp.close();
        return;
    }

    fp << str_name << std::endl;
    fp << str_address << std::endl;

    fp.close();
    std::cout << "Complete" << std::endl;
}

void read(){
    std::ifstream file("./address_info.txt");
    if(!file){
        std::cerr << "can not open file" <<std::endl;
        return;
    }

    int targetLine = 2;
    std::string line;
    int currentLine =1;

    while(std::getline(file,line)){
        if(currentLine == targetLine){
            std::cout << "Line " << targetLine << ": " << line << std::endl;
            break;
        }
        ++currentLine;
    }
    if(currentLine < targetLine){
        std::cerr << "there is no " << targetLine <<"line in file." <<std::endl;
    }

    file.close();
}

void find(const std::string& keyword)
{
    std::ifstream file("./address_info.txt");
    if(!file){
        std::cerr << "can not open file" <<std::endl;
        return;
    }

    std::size_t index = 0;
    std::string line;
    std::string key, content;
    bool found = false;
    while(std::getline(file, line))
    {
        std::cout << "Line " << (index+1) << ": " << line << std::endl;
        if(index % 2 == 0)
        {
            key = line;
            if(keyword == key)
            {
                found = true;
            }
        }
        else
        {
            content = line;
        }

        if(found == true && (index % 2 == 1))
        {
            break;
        }

        ++index;
    }

    if(found == false)
    {
        std::cerr << "not found item" <<std::endl;
    }
    else
    {
        std::cout << "found! key=" << key << ", content=" << content << std::endl;
    }

    file.close();
}

void update(const std::string& keyword){
    std::ifstream file("./address_info.txt"); // 원본 파일 읽기 모드로 열기
    std::string filePath("./address_info.txt");
    if (!file) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    std::ofstream tempFile("./temp.txt"); // 임시 파일 쓰기 모드로 열기
    if (!tempFile) {
        std::cerr << "임시 파일을 생성할 수 없습니다." << std::endl;
        file.close();
        return;
    }

    std::string line;
    bool found = false;

    std::string newString;    

    // 원본 파일에서 각 줄을 읽어 임시 파일에 작성
    while (std::getline(file, line)) {
        if (line.find(keyword) != std::string::npos && keyword.length() == line.length()) { // keyword가 줄에 포함되어 있는지 확인
            std::cout << "Enter Alter Name: " <<std::endl;
            std::getline(std::cin, newString);

            line.replace(line.find(keyword), keyword.length(), newString); // keyword를 newString으로 대체
            found = true;
        }
        tempFile << line << std::endl; // 임시 파일에 변경된 또는 원본 줄을 작성
    }

    tempFile.close();
    file.close();

    if (!found) {
        std::cout << "'" << keyword << "' is not found" << std::endl;
        std::remove("temp.txt"); // 변경 사항이 없는 경우 임시 파일 삭제
        return;
    }

    // 원본 파일 삭제
    if (std::remove(filePath.c_str()) != 0) {
        std::cerr << "can not remove origin file" << std::endl;
        return;
    }

    // 임시 파일을 원본 파일로 이름 변경
    if (std::rename("temp.txt", filePath.c_str()) != 0) {
        std::cerr << "temp file cannot change the name to origin file name" << std::endl;
    }

    std::cout << "파일이 성공적으로 업데이트되었습니다." << std::endl;
}

void delete_info(const std::string& del_keyword){

    std::string filePath("./address_info.txt");

    std::ifstream inputFile(filePath); // 원본 파일 읽기 모드로 열기
    if (!inputFile) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    std::ofstream tempFile("./temp.txt"); // 임시 파일 쓰기 모드로 열기
    if (!tempFile) {
        std::cerr << "임시 파일을 생성할 수 없습니다." << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    bool found = false;

    // 원본 파일에서 각 줄을 읽어 임시 파일에 작성 (키워드 포함 줄 제외)
    // 전문 일치로 바꿔야함.
    while (std::getline(inputFile, line)) {
        if (line.find(del_keyword) != std::string::npos) { // 키워드가 줄에 포함되어 있는지 확인
            found = true; // 키워드를 포함하는 줄을 발견했음을 표시
            continue; // 해당 줄을 건너뜀
        }
        tempFile << line << std::endl; // 임시 파일에 줄을 작성
    }

    inputFile.close();
    tempFile.close();

    if (!found) {
        std::cout << "'" << del_keyword << "'을(를) 포함한 줄을 찾을 수 없습니다." << std::endl;
        std::remove("temp.txt"); // 삭제할 줄이 없는 경우 임시 파일 삭제
        return;
    }

    // 원본 파일 삭제
    if (std::remove(filePath.c_str()) != 0) {
        std::cerr << "원본 파일을 삭제할 수 없습니다." << std::endl;
        return;
    }

    // 임시 파일을 원본 파일로 이름 변경
    if (std::rename("temp.txt", filePath.c_str()) != 0) {
        std::cerr << "임시 파일을 원본 파일로 이름 변경할 수 없습니다." << std::endl;
    }

    std::cout << "파일이 성공적으로 업데이트되었습니다." << std::endl;
}

