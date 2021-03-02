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
    std::string msg;
    int port;

    if (argc < 3) {
        std::cout << "Usage: " << cmd << " [ip_addr] [port] [message]" <<std::endl;
        return -1;
    }
    else {
        hostaddr = argv[1];
        port = atoi(argv[2]);
        msg = argv[3];
        std::cout << "We try to connect with as follow information.\nHost: " << hostaddr << ", port: " << port << std::endl;
    }

    try
    {
        ClientSocket client_socket ( hostaddr, port );
        client_socket.socketBufferInfo();

        std::string reply;      // = "RSP:ok#camera#img001.yuv#10077696";

        try
        {
            client_socket << msg;
            client_socket >> reply;

            std::vector<ZIPSA_MSG> packet = tokenize_getline(reply, ':');
            if (packet.at(0) == "RSP")
			{
				std::vector<ZIPSA_MSG> payload = tokenize_getline(packet.at(1), '#');
                if (payload.at(0) == "ok")
                {
                    std::string cmd = payload.at(1);
                    std::string filename = payload.at(2);
                    size_t filesize = atol(payload.at(3).c_str());
                    if (filesize > 0)
                    {
                        std::cout << "ready to receive file: " << filename << ", size= " << filesize << std::endl;
                        if ("camera" == cmd)
                        {
                            filename = "pic001.jpeg";
                            client_socket.recvFile(filename, filesize);
                        }
                    }
                    else
                    {
                        std::cout << "fail to convert integer value of file size" << std::endl;
                    }
                }
                std::cout << "We received this response from the server:\n" << reply << std::endl;
            }
        }
        catch ( SocketException& ) {}
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }

    return 0;
}

