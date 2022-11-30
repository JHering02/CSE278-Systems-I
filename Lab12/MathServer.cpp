/*
 *   C++ sockets on Unix and Windows
 *   Copyright (C) 2002
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

// Code modified by Qusay Mahmoud to address dynamic exception specifications whcih are deprecated since C++11

#include <iostream>
#include "PracticalSocket.h"  // For Socket, ServerSocket, and SocketException

using std::cout;
using std::endl;

const unsigned int RCVBUFSIZE = 1024;    // Size of receive buffer

void HandleTCPClient(TCPSocket *sock); // TCP client handling function

int sqr(int x) { return x*x; } // Squaring function for an int

int main(int argc, char *argv[]) {
    if (argc != 2) {                     // Test for correct number of arguments
        cerr << "Usage: " << argv[0] << " <Server Port>" << endl;
        exit(1);
    }

    unsigned short echoServPort = atoi(argv[1]);  // First arg: local port

    try {
        TCPServerSocket servSock(echoServPort);     // Server Socket object

        for (;;) {   // Run forever
            HandleTCPClient(servSock.accept());       // Wait for a client to connect
        }
    } catch (const std::exception& e) {
        cerr << e.what() << endl;
        exit(1);
    }

    return(0);
}

// TCP client handling function
void HandleTCPClient(TCPSocket *sock) {
    cout << "Handling client ";
    try {
        cout << sock->getForeignAddress() << ":";
    } catch (const std::exception& e) {
        cerr << "Unable to get foreign address" << endl;
        cerr << e.what() << endl;
    }
    try {
        cout << sock->getForeignPort();
    } catch (const std::exception& e) {
        cerr << "Unable to get foreign port" << endl;
        cerr << e.what() << endl;
    }
    cout << endl;

    int echoInt;
    int recvMsgSize;
    while ((recvMsgSize = sock->recv(&echoInt, RCVBUFSIZE)) > 0) { // Zero means
                                                         // end of transmission
        cout << "Received from client: "<<echoInt<<endl;
        int buffer = sqr(echoInt);
        //Echo back the squared integer
        sock->send(&buffer, recvMsgSize);
    }
    delete sock;
}
