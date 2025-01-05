#include "Account.h"



int main(void){
    int c_number=0;
    Account *account;

    while(1){
        showMenu();
        std::cout << "choice number: ";
        std::cin >> c_number;

        int account_number = 0;
        std::string account_name = "";
        int account_cash = 0;

        switch (c_number)
        {
        case 1:
            std::cout << "Enter the name: ";
            std::cin >> account_name;
            std::cout << "Enter the cash: ";
            std::cin >> account_cash;
            
            account->makeAccout(account_number, account_name, account_cash); //비정적 멤버 참조는 특정 개체에 상대적이어야 합니다 오류.
                                                                             //현상: Account::makeAccount() 선언 시 발생
                                                                             //원인: ??

            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        
        default:
            break;
        }
    }
}

void showMenu(){
    std::cout<<"------Menu------"<<std::endl;
    std::cout<<"1. Make Account " <<std::endl;
    std::cout<<"2. Deposite " <<std::endl;
    std::cout<<"3. withdraw " <<std::endl;
    std::cout<<"4. Account infomation all print" <<std::endl;
    std::cout<<"5. Exit" <<std::endl;
}
