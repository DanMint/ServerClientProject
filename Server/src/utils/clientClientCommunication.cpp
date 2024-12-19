#include "../../include/utils/clientClientCommunication.h"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

ClientClientConnection::ClientClientConnection(const ClientInformation &client1, const ClientInformation &lient2) : client1(client1), client2(client2){}

const std::vector<Message>& ClientClientConnection::getMessageExchange() const {
    return messageExchange;
}

const ClientInformation& ClientClientConnection::getClient1() const {
    return client1;
}

const ClientInformation& ClientClientConnection::getClient2() const {
    return client2;
}

void ClientClientConnection::addMessage(const Message &message) {
    messageExchange.emplace_back(message);
}

void ClientClientConnection::sendMessage(const std::string &sendersIp, const Message &message, const std::string &reciversIp) {
    int recieverSocket;
    if(sendersIp == client1.getIpAddress()) {
        recieverSocket = client2.getSocket();
    }
    else if(sendersIp == client2.getIpAddress()) {
        recieverSocket = client1.getSocket();
    }
    else {
        std::cout << "Cant send becuase user not in the list" << std::endl;
        return;
    }

    if(message.type == CHAR_ARR) {
        send(recieverSocket, std::get<char *>(message.message), message.length * sizeof(char), 0);
        addMessage(message);
    }
    else if(message.type == INT_ARR) {
        send(recieverSocket, std::get<int *>(message.message), message.length * sizeof(int), 0);
        addMessage(message);
    }
    else if(message.type == DOUBLE_ARR) {
        send(recieverSocket, std::get<double *>(message.message), message.length * sizeof(double), 0);
        addMessage(message);
    }
    else if(message.type == CHAR) {
        send(recieverSocket, std::get<char *>(message.message), message.length * sizeof(char), 0);
        addMessage(message);
    }
    else if(message.type == INT) {
        send(recieverSocket, std::get<int *>(message.message), message.length * sizeof(int), 0);
        addMessage(message);
    }
    else if(message.type == DOUBLE) {
        send(recieverSocket, std::get<double *>(message.message), message.length * sizeof(double), 0);
        addMessage(message);
    }
    else {
        std::cout << "Unkown message type" << std::endl;
    }
}
