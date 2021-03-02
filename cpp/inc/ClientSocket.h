// Definition of the ClientSocket class

#ifndef ClientSocket_class
#define ClientSocket_class

#include "Socket.h"


class ClientSocket : private Socket
{
 public:

    ClientSocket ( std::string host, unsigned int port );
    virtual ~ClientSocket(){};

    const ClientSocket& operator << ( const std::string& ) const;
    const ClientSocket& operator >> ( std::string& ) const;

    void recvFile ( const std::string&, size_t fileSize );
    void sendFile ( const std::string fname );
    void socketBufferInfo ( );
};


#endif
