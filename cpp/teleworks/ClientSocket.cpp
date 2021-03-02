// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"


ClientSocket::ClientSocket( std::string host, unsigned int port )
{
    if ( ! Socket::create() )
    {
        throw SocketException( "Could not create client socket." );
    }

    if ( ! Socket::connect( host, port ) )
    {
        throw SocketException( "Could not bind to port." );
    }

}


const ClientSocket& ClientSocket::operator << ( const std::string& s ) const
{
    if ( ! Socket::send( s ) )
    {
        throw SocketException( "Could not write to socket." );
    }

    return *this;

}


const ClientSocket& ClientSocket::operator >> ( std::string& s ) const
{
    if ( ! Socket::recv( s ) )
    {
        throw SocketException( "Could not read from socket." );
    }

    return *this;
}

void ClientSocket::recvFile ( const std::string& fname, size_t fileSize )
{
    if ( !Socket::recvFile( fname, fileSize) )
    {
        throw SocketException( "Could not read from socket." );
    }
}

void ClientSocket::sendFile ( const std::string fname )
{
    if ( !Socket::sendFile( fname ) )
    {
        throw SocketException ( "Could not accept socket." );
    }
}

void ClientSocket::socketBufferInfo ( )
{
    Socket::get_socket_option();
}
