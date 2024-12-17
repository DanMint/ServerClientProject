#ifndef STARTSERVER_H
#define STARTSERVER_H

#include <iostream>
#include <netinet/in.h>


/** 
 * @function createSocketSockaddrBind
 * 
 * @brief Creates server with given port number
 * 
 * @param portNumber = for desierd port number
 * @param protocolType = desierd protocol type. 0 = TCP and 1 = UDP
 * 
 * @return retunrs a pair consisting number of listening socket and server structure
 * 
 * @details
 * - Create server socket
 * - Configure the sockaddr_in for the server
 * - Bind socket with sockaddr_in struct of the server
 */
std::pair<int, sockaddr_in> createSocketSockaddrBind(const int portNumber, const int protocolType);

/** 
 * @function startServer
 * 
 * @brief Server is listening with the listening port and starts managing client connections
 * 
 * @param listeningSocket = Listening socket number
 * @param maxQueuedConnections = Maximum allowed client queue that are not yet accepted
 * @param serverInformation = Servers information structure
 * 
 * @return Nothing
 * 
 * @details
 * - Starts listening on the listening socket
 * - When a clinet wants to connect allows
 * - Creates a unique TCP socket for client (in TCP each connection gets a unique port for that connection)
 * - Exchnages with server
 * - MORE TO COME
 */
void startServer(const int listeningSocket , const int maxQueuedConnections, const sockaddr_in &serverInformation);

void handleClient(const int clientSocket, const sockaddr_in &clientsInformation);

#endif

