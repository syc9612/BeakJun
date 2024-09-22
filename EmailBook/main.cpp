#include "crud.h"

int main(){


    std::cout << "--------------" << std::endl;
    //case 함수 사용


    /*
    Error: Unable to perform this action because the process is running
    해결: 스택오버플로우에서 해답을 찾을 수 있었다. launch.json의 "externalConsole": true로 바꾸면, 외부 터미널이 열리면서 외부 터미널에 값을 입력할 수 있다.
    */
    //enroll_nm_adr();
    //read();
    //address_check("syc9612@naver.com");
    //read()로 읽고 그냥 종료되어버리는 현상 발견하여 이렇게 변경.
    //update("77");
    delete_info("44");
    std::cout << "Press Enter to continue..." << std::endl; // 콘솔이 닫히지 않도록 대기
    std::cin.ignore(); // 사용자가 Enter를 누를 때까지 대기
}