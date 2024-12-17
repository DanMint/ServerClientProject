#include "../../include/utils/serverAdmin.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <memory>
#include <pthread.h>

std::pair<int, sockaddr_in> createSocketSockaddrBind(const int portNumber, const int protocolType) {
    int serverSocket = socket(AF_INET, ((protocolType == 0)? SOCK_STREAM : SOCK_DGRAM), 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = portNumber;
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    return {serverSocket, serverAddress};
}

void startServer(const int listeningSocket , const int maxQueuedConnections, const sockaddr_in &serverInformation) {
    listen(listeningSocket, maxQueuedConnections);

    while (true) {
        sockaddr_in clientAddress;
        socklen_t addrLen = sizeof(clientAddress);
        /// here add check if client is blacklisted or has been connected before
        int clientSocket = accept(listeningSocket, (struct sockaddr*)&clientAddress, &addrLen);

        char clientIP[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddress.sin_addr), clientIP, INET_ADDRSTRLEN);

        std::cout << "Client from " << clientIP << " on port " << clientSocket << std::endl;


        // implement multithreading here
        handleClient(clientSocket, clientAddress);
       
    }

}

void handleClient(const int clientSocket, const sockaddr_in &clientsInformation) {
    pthread_t client;
    pthread_create(&client, nullptr, nullptr, nullptr);
}


