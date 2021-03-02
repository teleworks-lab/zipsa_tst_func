#include "BuildPlatform.h"
#include "ServerSocket.h"
#include "ClientSocket.h"
#include "SocketException.h"
#include "Queue.h"
#include "utils.h"
#include "CmdExecutor.h"
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <thread>
#include <cstring>

std::string g_imgFile;
void xfer_file(int sig);
float get_distance_zval();


// commands executor
//
int cmd_execution(std::vector<std::string> cmdinfo, std::string& res_str)
{
	size_t payload_number;
	int ret = -1;
	char buf[PATH_MAX];
	bool exeresult = false;

	CmdExecutor executor;

	payload_number = cmdinfo.size();
	for (size_t i = 0; i < cmdinfo.size(); i++)
	{
		std::cout << i << ": " << cmdinfo[i] << std::endl;
	}
	
	if ("camera" == cmdinfo[0])
	{
		std::string param1 = trim( cmdinfo[1] );
		if ("shot" == param1)
		{
			exeresult = executor.capture_camera_oneshot();
            if (exeresult)
            {
                g_imgFile = executor.get_result_file_name();
                sprintf(buf, "RSP:ok#%s#%s#%ld\n", cmdinfo[0].c_str(), executor.get_result_file_name().c_str(), executor.get_result_file_size());
            }
		}
	}
	else if ("microphone" == cmdinfo[0])
	{
		std::string param1 = trim( cmdinfo[1] );
		if ("record" == param1)
		{
			exeresult = executor.record_voice_mircophone();
            if (exeresult)
            {
                sprintf(buf, "RSP:ok#%s#%s#%ld\n", cmdinfo[0].c_str(), executor.get_result_file_name().c_str(), executor.get_result_file_size());
            }
		}
		else if ("play" == param1)
		{
			if (payload_number >= 3)
            {
                int n = atoi(cmdinfo[2].c_str());
                exeresult = executor.play_microphone_voice(n);
            }
            else
            {
                exeresult = executor.play_microphone_voice(0);
            }

            if (exeresult)
            {
                sprintf(buf, "RSP:ok#%s#%s\n", cmdinfo[0].data(), param1.data());
            }
		}
	}
	else if ("speaker" == cmdinfo[0])
	{
		if ("soundplay" == cmdinfo[1])
		{
			int ch = atoi(cmdinfo[2].c_str());
			exeresult = executor.speaker_sound(ch);
            if (exeresult)
            {
                sprintf(buf, "RSP:ok#%s#%s\n", cmdinfo[0].c_str(), cmdinfo[1].c_str());
            }
		}
	}
    else if ("tof" == cmdinfo[0])
    {
        std::string param1 = trim( cmdinfo[1] );
        if ("distance" == param1)
        {
            exeresult = executor.tof_measure_distance();
            if (exeresult)
            {
                sprintf(buf, "RSP:ok#%s#%s#%f\n", cmdinfo[0].c_str(), param1.c_str(), get_distance_zval());
            }
        }
    }
    

	if (true == exeresult)
	{
		res_str = buf;
		ret = executor.get_result_code();
	}
	else
	{
		sprintf(buf, "RSP:impossible#%s\n", cmdinfo[0].c_str());
		res_str = buf;
	}
	return ret;
}

float get_distance_zval()
{
    std::string str_dist_val;
    float dist_val = 0.0f;

    std::string filePath = "/tmp/depthZ.txt";
    std::ifstream openFile(filePath.data());
    if (openFile.is_open())
    {
        std::getline(openFile, str_dist_val);
        dist_val = atof(str_dist_val.c_str());
        openFile.close();
    }
    else {
        std::cout << "open failure: depthZ.txt" << std::endl;
    }
    std::cout << "get Distance Z from reading depthZ.txt = " << str_dist_val << std::endl;
    return dist_val;
}

void xfer_file()
{
    try
    {
        ClientSocket client_socket ( "192.168.5.10", 30001 );
		try
		{
            client_socket.sendFile(g_imgFile);
		}
		catch( SocketException& ) {}
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }
}

//---- Main thread --------------------------
//
int main( int argc, char* argv[] )
{
    int port_num;

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
		
            try
            {
                while ( true )
                {
                    std::string req_data, rsp;
                    bool xfer_file = false;

                    new_sock >> req_data;

                    std::vector<std::string> packet = tokenize_getline(req_data, ':');
                    if (packet[0] == "REQ")
                    {
                        std::vector<std::string> cmdinfo = tokenize_getline(packet[1], '#');
                        std::string cmdtype = cmdinfo[0];

                        int res = cmd_execution(cmdinfo, rsp);
                        if (res > 0)
                        {
                            if ("camera" == cmdtype) {
                                xfer_file = true;
                            }
                        }
                        std::cout << "respose packet= {" << rsp << "}" << std::endl;
                        new_sock << rsp;
                    }
                    else if (packet[0] == "RSP")
                    {

                    }
                    // After send respose to the client, then send cam image file in case of camera request.
                    if (xfer_file)
                    {
                        sleep(1);
                        void xfer_file();
						std::thread t1(xfer_file);
                        t1.join();
                    }
                }
            }
            catch ( SocketException& e ) 
            {
                std::cout << "disconnect client: " << std::endl;
            }
        }
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught: " << e.description() << "\nExiting.\n";
    }

    return 0;
}
