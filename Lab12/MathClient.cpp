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

// Code modified by Qusay Mahmoud to address dynamic exception specifications which are deprecated since C++11

#include <iostream>           // For cerr and cout
#include <cstring>
#include "PracticalSocket.h"  // For Socket and SocketException

using std::cout;
using std::endl;

const int RCVBUFSIZE = 1024;    // Size of receive buffer

int main(int argc, char *argv[]) {
    if (argc != 4) {     // Test for correct number of arguments
        cerr << "Usage: " << argv[0]
             << " <Server Name> <Server Port#> <message>" << endl;
        exit(1);
    }

    string servAddress = argv[1]; // First arg: server address
    unsigned short echoServPort = (atoi(argv[2]));
    int echoInt = atoi(argv[3]);   // Second arg: string to echo
    int echoIntLen = sizeof(echoInt);   // Determine input length

    try {
        // Establish connection with the echo server
        TCPSocket sock(servAddress, echoServPort);

        // Send the string to the echo server
        sock.send(&echoInt, echoIntLen);

        int echoInt;
        int bytesReceived = 0;              // Bytes read on each recv()
        int totalBytesReceived = 0;         // Total bytes read
        // Receive the same string back from the server
        cout << "Received: ";               // Setup to print the echoed string
        while (totalBytesReceived < echoIntLen) {
            // Receive up to the buffer size bytes from the sender
            if ((bytesReceived = (sock.recv(&echoInt, RCVBUFSIZE))) <= 0) {
                cerr << "Unable to read";
                exit(1);
            }
            totalBytesReceived += bytesReceived;     // Keep tally of total bytes
            // echoBuffer[bytesReceived] = '\0';        // Terminate the string!
            cout << echoInt;                      // Print the echo buffer
        }
        cout << endl;

    } catch(std::exception &e) {
        cerr << e.what() << endl;
        exit(1);
    }

    return(0);
}
