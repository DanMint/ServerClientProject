#ifndef CLIENTINFORMATIO_H
#define CLIENTINFORMATIO_H

#include <string>
#include <unordered_map>
#include <vector>
#include <variant>
#include "message.h"

/** 
 * @class ClientInformation
 * 
 * @brief Stores information about a connected client
 * 
 * @private
 * 
 * @param clientSocket : 
 * @param ipAddress : 
 * @param id : 
 * @param Friend: 
 * @param friendList : 
 * 
 * @public
 * 
 * @function ClientInformation(const int serverPort, const int protocolType)
 * - 
 * @function getSocket : Initializes a new client with socket number, ip address and unique id
 * @function getIpAddress : Gets the socket
 * @function getFriendList : Gets friends list
 * @function checkIfFriends : Checks if given person a friend of this client
 * @function getFriend : Gets a friends from friend list
 * @function addFriend : Adds new friend to the list
 * @function addMessageToFriend : Adds a message to the friend struct
 */

class ClientInformation {
    private:
        int clientSocket;
        std::string ipAddress;
        std::string id;

        struct Friend {
            std::string ipAddress;
            std::string id;
            std::vector<std::pair<int, Message>> messagesExchanged; 
        };

        
        std::unordered_map<std::string, Friend> friendList;

    public:
        ClientInformation(const int clientSocket, const std::string &ipAddress, const std::string &id);

        int getSocket() const;

        const std::string getIpAddress() const;

        const std::unordered_map<std::string, Friend> getFriendList() const;

        bool checkIfFriends(const std::string &friendsIp, const std::string &friendsId) const;

        const Friend* getFriend(const std::string &friendsIp, const std::string &friendsId);

        void addFriend(const std::string &friendsIp, const std::string &friendsId);

        void addMessageToFriend(const std::string &friendsIp, const std::string& friendsId, const Message &message);

};

#endif