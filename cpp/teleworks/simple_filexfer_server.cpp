#include "ServerSocket.h"
#include "SocketException.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <thread>



int main( int argc, char* argv[] )
{
	int port_num;
	pthread_t p_thread;
	int thr_id, rc;

	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " [port]" << std::endl;
		return -1;
	}
	
	std::string sPort = argv[1];
	if (!isNumber(sPort))
	{
		std::cout << "Wrong port number.. exit!" << std::endl;
		return -1;
	}
	else
	{
		port_num = atoi(sPort.c_str());
	}
	
	std::cout << "server is running....(port nmber= " << port_num << ")" << std::endl;
    try
    {
		// Create the socket
		ServerSocket server( port_num );

		while ( true )
		{
			ServerSocket new_sock;
			server.accept( new_sock );
			std::cout << "accept new socket for client" << std::endl;
			new_sock.socketBufferInfo();

            try
			{
                new_sock.sendFile("/home/jhnam/workspace/DQ1/temp/sample_img01.png");
            }
            catch ( SocketException& ) {}
		}
	}
	catch ( SocketException& e )
	{
		std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	return 0;
}
