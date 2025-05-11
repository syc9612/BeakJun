#include "NetworkService.h"
#include <iostream>

#define GET_SERVICE_INSTANCE() NetworkService::GetInstance()

int main() {
    if (GET_SERVICE_INSTANCE()->IsIPv6Enabled()) { // ->로 멤버 함수 호출
        GET_SERVICE_INSTANCE()->Connect();         // ->로 다른 멤버 함수 호출
    }
    return 0;
}