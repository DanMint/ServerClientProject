#ifndef SERVER_H
#define SERVER_H

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
#include <pthread.h>

/** 
 * @class Server
 * 
 * @brief Manages connections from clients
 * 
 * @private
 * 
 * @param serverPort : Port of the server
 * @param serverSocket : Created listening socket
 * @param serverAddress : Servers structure that holds the servers information (IP, PORT, etc...)
 * 
 * @public
 * 
 * @function Server(const int serverPort, const int protocolType)
 * - 
 * @function int getExpectedSeqNum() : Returns the next expected sequence number.
 * @function void increaseExpectedSeqNum() : Increments the expected sequence number.
 * @function void bufferPacket(const pkt &packet) : Buffers a received packet.
 * @function bool isBuffered(int seqnum) : Checks if a packet is already buffered.
 * @function pkt getBufferedPacket(int seqnum) : Retrieves a buffered packet.
 * @function void removeBufferedPacket(int seqnum) : Removes a buffered packet.
 */
class Server {
    private:
        int serverPort;
        int serverSocket;
        sockaddr_in serverAddress;

    public:
        Server(const int serverPort, const int protocolType);

        void start();

        void closeServerSocket();

};

#endif