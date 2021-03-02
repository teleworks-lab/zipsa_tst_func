// Definition of the Socket class

#ifndef Socket_class
#define Socket_class


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>


const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 1024;
const int XFERSZ = 1024;

class Socket
{
public:
    Socket();
    virtual ~Socket();

    // Server initialization
    bool create();
    bool bind( const unsigned int port );
    bool listen() const;
    bool accept( Socket& ) const;

    // Client initialization
    bool connect ( const std::string host, const unsigned int port );

    // Data Transimission
    bool send( const std::string ) const;
    bool sendFile( const std::string fname );
    ssize_t recv( std::string& ) const;
    bool recvFile ( const std::string fname, size_t file_size );


    void set_non_blocking ( const bool );

    bool is_valid() const { return m_sock != -1; }
    bool get_socket_option();

private:

    int           m_sock;
    sockaddr_in   m_addr;
};

#endif
