#include "../../include/utils/currentConnections.h"
#include <iostream>

CurrentConnections::CurrentConnections() {
    amountOfCurrentConnections = 0;
}

const std::string* CurrentConnections::getIdFromIp(const std::string &ip) const {
    auto idRecord = ipToId.find(ip);
    if(idRecord != ipToId.end()) {
        return &idRecord->second;
    }

    return nullptr;
}

const std::string* CurrentConnections::getIpFromId(const std::string &id) const {
    auto ipRecord = idToIp.find(id);
    if(ipRecord != idToIp.end()) {
        return &ipRecord->second;
    }

    return nullptr;

}

const pthread_t* CurrentConnections::getThreadFromIp(const std::string &ip) const {
    auto thread = ipToThread.find(ip);
    if(thread != ipToThread.end()) {
        return &thread->second;
    }

    return nullptr;

}

const ClientInformation* CurrentConnections::getClientFromIp(const std::string &ip) const {
    auto client = ipToClient.find(ip);
    if(client != ipToClient.end()) {
        return &client->second;
    }

    return nullptr;
}
                

void CurrentConnections::addNewCurrentUser(const std::string &ip, const std::string &id, const pthread_t &thread, const ClientInformation &client) {
    auto ifRecordExists = ipToId.find(ip); 
    if(ifRecordExists != ipToId.end()) {
        std::cout << "IP ALREADY FOUND CANT ADD" << std::endl;
        return;
    }
    ipToId[ip] = id;
    idToIp[id] = ip;
    ipToThread[ip] = thread;
    ipToClient[ip] = client;
}