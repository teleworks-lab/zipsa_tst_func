#include "ClientSocket.h"
#include "SocketException.h"
#include "Queue.h"
#include "utils.h"
#include <iostream>
#include <string>

int main ( int argc, char* argv[] )
{
    std::string cmd = argv[0];
    std::string hostaddr;
    std::string filepath;
    int port;
    size_t filesize = 0;

    if (argc < 3) {
        std::cout << "Usage: " << cmd << " [ip_addr] [port] [filpath] [filesize]" << std::endl;
        return -1;
    }
    else {
        hostaddr = argv[1];
        port = atoi(argv[2]);
        filepath = argv[3];
        if (nullptr != argv[4]) {
            filesize = atol(argv[4]);
        }

        std::cout << "We try to connect with as follow information.\nHost: " << hostaddr << ", port: " << port << std::endl;
    }

    try
    {
        ClientSocket client_socket ( hostaddr, port );
        client_socket.socketBufferInfo();

        std::string reply;      // = "RSP:ok#camera#img001.yuv#10077696";
        sleep(1);

        try
        {
            //client_socket.recvFile(filepath, filesize);
            client_socket.sendFile(filepath);
        }
        catch ( SocketException& ) {}
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }

    return 0;
}
