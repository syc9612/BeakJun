#include "EmailBook.h"
#include <iostream>

int main(){


    std::cout << "--------------" << std::endl;
    //case 함수 사용


    /*
    Error: Unable to perform this action because the process is running
    해결: 스택오버플로우에서 해답을 찾을 수 있었다. launch.json의 "externalConsole": true로 바꾸면, 외부 터미널이 열리면서 외부 터미널에 값을 입력할 수 있다.
    */
    int client;
   
    std::cout << "input the number of people" << std::endl;
    std::cin >> client;

    EmailBook* clients = { new EmailBook[client] };
    int index{ 0 };

    for(;;){
        while ( index < client){
            std::cout << "Enter the name " << std::endl;
            char client_name[100];
            std::cin >> client_name;

            clients[index].setName(client_name);
            std::cout << std::endl;

            std::cout << "Enter the Email Address " << std::endl;
            char client_Address[100];
            std::cin >> client_Address;

            clients[index].setAddress(client_Address);
            std::cout << std::endl;

            index++;

            std::cout << " >> save the info . " << std::endl << std::endl;
        }
    std::cout << "################################" << std::endl;
    std::cout << " 1. Show the name and Address" << std::endl;
    std::cout << " 2. Exit" << std::endl;

    int select_menu{0};
    std::cin >> select_menu;
    char name[100];
    std::string Address{0};

    int menu{0};


    switch (select_menu){
        case 1:
        std::cout << "select the menu. 1:show info 2: delete name 3: delete address" << std::endl;
        std::cin >> menu;

        if (menu == 1){
            std::cout << "print info" << std::endl;
            std::cout << "enter the name : ";
            std::cin >> name;

            for (int i=0; i< client; i++){
                if(clients[i].getName() == name){
                    clients[i].readAddress();
                }
            std::cout << "no matched info" << std::endl;
            }
        }
        else if(menu == 2){

        }
        break;

        case 2:
            std::cout << "Close the Program" << std::endl;
            goto EXIT;
            break;
        
        default:
            std::cout << "enter the wrong info" << std::endl;
            break;
        }
    }
    EXIT:
    delete[] clients;
}