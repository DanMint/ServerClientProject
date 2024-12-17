#ifndef CLIENTINFORMATIO_H
#define CLIENTINFORMATIO_H

#include <string>
#include <unordered_map>
#include <vector>
#include <variant>
#include "message.h"

class ClientInformation {
    private:
        int port;
        std::string ipAddress;
        using messageType = std::variant<char*, int*, double*, char, int, double>;

        struct Friend {
            int port;
            std::string ipAddress;
            std::string name;
            std::vector<messageType> messagesExchanged; 
        };

        
        std::unordered_map<std::string, Friend> friendList;

    public:
        ClientInformation(const int port, const std::string ip);


};

#endif