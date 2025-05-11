#ifndef NETWORK_SERVICE_H
#define NETWORK_SERVICE_H

class NetworkService {
public:
    static NetworkService* GetInstance();
    bool IsIPv6Enabled();
    void Connect();
private:
    NetworkService() {} // private 생성자
    bool ipv6_enabled = true;
};

#endif