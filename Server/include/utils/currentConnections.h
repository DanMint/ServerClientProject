#ifndef CURRENTCONNECTIONS_H
#define CURRENTCONNECTIONS_H

#include "clientInformation.h"

#include <unordered_map>
#include <string>

class CurrentConnections {
    private:
        int amountOfCurrentConnections;
        std::unordered_map<std::string, std::string> ipToId;
        std::unordered_map<std::string, std::string> idToIp;
        std::unordered_map<std::string, pthread_t> ipToThread;
        std::unordered_map<std::string, ClientInformation> ipToClient;

    public:
        CurrentConnections();

        const std::string* getIdFromIp(const std::string &ip) const;

        const std::string* getIpFromId(const std::string &id) const;

        const pthread_t* getThreadFromIp(const std::string &ip) const;

        const ClientInformation* getClientFromIp(const std::string &ip) const;

        void addNewCurrentUser(const std::string &ip, const std::string &id, const pthread_t &thread, const ClientInformation &client); 
                
};

#endif