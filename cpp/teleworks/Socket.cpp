// Implementation of the Socket class.

#include "Socket.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <iostream>


Socket::Socket() :
  m_sock ( -1 )
{
    memset ( &m_addr, 0, sizeof ( m_addr ) );
}

Socket::~Socket()
{
    if ( is_valid() )
        ::close ( m_sock );
}

bool Socket::create()
{
    m_sock = socket ( AF_INET, SOCK_STREAM, 0 );

    if ( ! is_valid() )
        return false;

    // TIME_WAIT - argh
    int on = 1;
    if ( setsockopt ( m_sock, SOL_SOCKET, SO_REUSEADDR, ( const char* ) &on, sizeof ( on ) ) == -1 )
        return false;

    return true;
}

bool Socket::bind ( const unsigned int port )
{
    if ( !is_valid() )
    {
        return false;
    }

    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
    m_addr.sin_port = htons ( (uint16_t)port );

    int bind_return = ::bind ( m_sock,
			     ( struct sockaddr * ) &m_addr,
			     sizeof ( m_addr ) );

    if ( bind_return == -1 )
    {
        return false;
    }

    return true;
}


bool Socket::listen() const
{
    if ( !is_valid() )
    {
        return false;
    }

    int listen_return = ::listen ( m_sock, MAXCONNECTIONS );


    if ( listen_return == -1 )
    {
        return false;
    }

    return true;
}


bool Socket::accept ( Socket& new_socket ) const
{
    int addr_length = sizeof ( m_addr );
    new_socket.m_sock = ::accept ( m_sock, ( sockaddr * ) &m_addr, ( socklen_t * ) &addr_length );

    if ( new_socket.m_sock <= 0 )
        return false;
    else
        return true;
}


bool Socket::send ( const std::string s ) const
{
    ssize_t status = ::send ( m_sock, s.c_str(), s.size(), MSG_NOSIGNAL );
    if ( status == -1 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

// new design : for transferring big data like image file
//
bool Socket::sendFile( const std::string fname )
{
    char buf[ XFERSZ ];
    size_t n_size, accum;
    bool res = true;
    int count = 0;
    ssize_t status;

    FILE *fd = fopen(fname.c_str(), "rb");
    if (fd == NULL)
    {
        std::cout << "Error: fail to open file - " << fname << std::endl;
        return false;
    }

    accum = 0;
    std::cout << "sending..." << std::endl;

    while (feof(fd) == 0)
    {
        n_size = fread(buf, 1, sizeof(buf), fd);

        if (n_size <= sizeof(buf))
        {
            int nRet = ferror(fd);
            if (nRet != 0)
            {
                std::cout << "File read error!!" << std::endl;
                res = false;
                break;
            }
            else
            {
                status = ::send(m_sock, buf, n_size, MSG_NOSIGNAL);
                if (status == -1)
                {
                    std::cout << "[Socket::sendFile] send error" << std::endl;
                    res = false;
                    break;
                }
                else
                {
                    count++;
                    accum += status;
                    std::cout << "(" << count << ") " << status << " : " << accum << std::endl;
                }
            }
        }
        else
        {
            std::cout << "something wrong to read file.." << std::endl;
            res = false;
            break;
        }
    }
    std::cout << "-- Tx End --" << std::endl;
    fclose(fd);
    return res;
}

ssize_t Socket::recv ( std::string& s ) const
{
    char buf[ MAXRECV + 1 ];

    s = "";
    memset ( buf, 0, MAXRECV + 1 );

    ssize_t status = ::recv ( m_sock, buf, MAXRECV, 0 );

    if ( status == -1 )
    {
        std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
        return 0;
    }
    else if ( status == 0 )
    {
        return 0;
    }
    else
    {
        s = buf;
        return status;
    }
}

// new design : for receiving big data 
//
bool Socket::recvFile ( const std::string fname, size_t file_size )
{
    char buf[ XFERSZ ];
    size_t written;
    long n_size;
    bool res = true;
    int count = 0;

    FILE *fd = fopen(fname.c_str(), "wb");

    if (NULL == fd)
    {
        std::cout << "Fail to open file - " << fname << std::endl;
        return false;
    }

    n_size = file_size;
    while (n_size > 0)
    {
        size_t status = ::recv ( m_sock, buf, XFERSZ, 0 );
        if (status > 0)
        {
            std::cout << count << " ";
            written = fwrite(buf, sizeof(char), status, fd);
            if (written != status)
                std::cout << "[Socket::sendFile] Error! did not write to file as being read from socket" << std::endl;

            n_size -= status;
            count++;
        }
        else
        {
            std::cout << "socke receive error" << std::endl;
            res = false;
            break;
        }
    }
    std::cout << " Received .." << std::endl;
    fclose(fd);
    return res;
}


bool Socket::connect ( const std::string host, const unsigned int port )
{
    if ( ! is_valid() ) 
        return false;

    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons ( (uint16_t)port );

    int status = inet_pton ( AF_INET, host.c_str(), &m_addr.sin_addr );

    if ( errno == EAFNOSUPPORT ) 
        return false;

    status = ::connect ( m_sock, ( sockaddr * ) &m_addr, sizeof ( m_addr ) );

    if ( status == 0 )
        return true;
    else
        return false;
}

void Socket::set_non_blocking ( const bool b )
{

    int opts;

    opts = fcntl ( m_sock, F_GETFL );

    if ( opts < 0 )
    {
        return;
    }

    if ( b )
        opts = ( opts | O_NONBLOCK );
    else
        opts = ( opts & ~O_NONBLOCK );

    fcntl ( m_sock, F_SETFL, opts );
}

bool Socket::get_socket_option()
{
    int snd_buffer, rcv_buffer;
    socklen_t len;

    if ( !is_valid() )
    {
        return false;
    }

    len = sizeof(snd_buffer);
    if (getsockopt(m_sock, SOL_SOCKET, SO_SNDBUF, (void *)&snd_buffer, &len) < 0)
    {
        std::cout << "getsockopt error - send buffer" << std::endl;
        return false;
    }
    len = sizeof(rcv_buffer);
    if (getsockopt(m_sock, SOL_SOCKET, SO_RCVBUF, (void *)&rcv_buffer, &len) < 0)
    {
        std::cout << "getsockopt error - send buffer" << std::endl;
        return false;
    }

    std::cout << "Input buffer size: " << rcv_buffer << std::endl;
    std::cout << "Output buffer size: " << snd_buffer << std::endl;

    return true;
}
