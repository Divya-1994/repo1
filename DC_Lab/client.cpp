#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int main()
{
    int client;
    int portNum = 1600; // NOTE that the port number is same for both client and server
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }


    cout << "\n=> Socket client has been created..." << endl;
    
    /* 
        The variable serv_addr is a structure of sockaddr_in. 
        sin_family contains a code for the address family. 
        It should always be set to AF_INET.
        htons() converts the port number from host byte order 
        to a port number in network byte order.
    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    // this function returns returns 1 if the IP is valid
    // and 0 if invalid

    /* ---------- CONNECTING THE SOCKET ---------- */
    /* ---------------- connect() ---------------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum << endl;

    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    // Once it reaches here, the client can send a message first.

    do {
        cout << "Client: ";
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);
        cout << endl;

    } while (!isExit);
    /* 
        Once the server presses # to end the connection,
        the loop will break and it will close the server 
        socket connection and the client connection.
    */

    cout << "\n=> Connection terminated.\nGoodbye...\n";

    close(client);
    return 0;
}