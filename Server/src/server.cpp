#include "../include/server.h"
#include "../include/utils/serverAdmin.h"

#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <unordered_map>
#include <cassert>
#include <arpa/inet.h>
#include <any>
#include <variant>
#include <memory>

#define PORT 3490
#define BUFFER_SIZE 1024


Server::Server(const int serverPort, const int protocolType) {
    this->serverPort = serverPort;
    auto serverCreation = createSocketSockaddrBind(serverPort, protocolType);
    this->serverSocket = serverCreation.first;
    this->serverAddress = serverCreation.second;
}

void Server::start() {
    listen(serverSocket, 5);

    while(true) {
        sockaddr_in clientAddr;
        socklen_t addrLen = sizeof(clientAddr);
        // accept client connection
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);
        // Test::testClientSocket(clientSocket);

        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIP, INET_ADDRSTRLEN);

        std::cout << "Client from " << clientIP << " on port " << clientSocket << std::endl;
    }
}


void Server::closeServerSocket() {
    close(serverSocket);
}