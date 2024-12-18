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
   
}


void Server::closeServerSocket() {
    close(serverSocket);
}