#ifndef CLIENTCLIENTCONNECTION_H
#define CLIENTCLIENTCONNECTION_H

#include "clientInformation.h"
#include <queue> 

/** 
 * @class ClientClientConnection
 * 
 * @brief Handels client to client communication after the connection has been established
 * 
 * @private
 * 
 * @param client1 : first client
 * @param client2 : second client
 * @param messageExchange : all the messages exchanged between the two

 * @public
 * 
 * @function ClientClientConnection(const ClientInformation &client1, const ClientInformation &client2) : Parametrised constructir
 * - 
 * @function getMessageExchange : gets all the messages excahed between the two clients
 * @function getClient1 : gets client 1 information
 * @function getClient2 : gets client 2 infromation
 * @function addMessage : add message to message exchange
 * @function sendMessage : send message to client1 or client2
 */


class ClientClientConnection {
    private:
        ClientInformation client1;
        ClientInformation client2;
        std::vector<Message> messageExchange;

    public:
        ClientClientConnection(const ClientInformation &client1, const ClientInformation &client2);

        const std::vector<Message>& getMessageExchange() const;

        const ClientInformation& getClient1() const;

        const ClientInformation& getClient2() const;

        void addMessage(const Message &message);

        void sendMessage(const std::string &sendersIp, const Message &message, const std::string &reciversIp);
};

#endif