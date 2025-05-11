#include "NetworkService.h"
#include <iostream>

NetworkService* NetworkService::GetInstance() {
    static NetworkService instance;
    return &instance;
}

bool NetworkService::IsIPv6Enabled() {
    return ipv6_enabled;
}

void NetworkService::Connect() {
    std::cout << "Connecting with " << (ipv6_enabled ? "IPv6" : "IPv4") << std::endl;
}