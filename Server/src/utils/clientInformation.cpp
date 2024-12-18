#include "../../include/utils/clientInformation.h"

#include <iostream>

ClientInformation::ClientInformation(const int clientSocket, const std::string &ipAddress, const std::string &id) {
    this->clientSocket = clientSocket;
    this->ipAddress = ipAddress;
    this->id = id;
}

int ClientInformation::getSocket() const {
    return clientSocket;
}

const std::string ClientInformation::getIpAddress() const {
    return ipAddress;
}

const std::unordered_map<std::string, ClientInformation::Friend> ClientInformation::getFriendList() const {
    return friendList;
}

bool ClientInformation::checkIfFriends(const std::string &friendsIp, const std::string &friendsId) const {
    auto findFriend = friendList.find(friendsIp);
    if(findFriend != friendList.end() && findFriend->second.id == friendsId) { 
        return true;
    }
    return false;
}

const ClientInformation::Friend*  ClientInformation::getFriend(const std::string &friendsIp, const std::string &friendsId) {
    if(ClientInformation::checkIfFriends(friendsIp, friendsId)) {
        return &friendList[friendsIp];
    }
    return nullptr;
}

void ClientInformation::addFriend(const std::string &friendsIp, const std::string &friendsId) {
    if(!ClientInformation::checkIfFriends(friendsIp, friendsId)) {
        Friend newFriend{friendsIp, friendsId};
        friendList[friendsIp] = newFriend;
    }
}

void ClientInformation::addMessageToFriend(const std::string &friendsIp, const std::string& friendsId, const Message &message) {
    if(ClientInformation::checkIfFriends(friendsIp, friendsId)) {
        size_t amountOfMessagesExchanged = friendList[friendsIp].messagesExchanged.size();
        friendList[friendsIp].messagesExchanged.emplace_back(std::pair{amountOfMessagesExchanged + 1, message});
    }
    std::cout << "Did add message, No such friend exist" << std::endl;
}
