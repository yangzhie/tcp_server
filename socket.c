/* socket.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IP "69.16.231.59" /* www.gooogle.se */
#define PORT 80           /* HTTP */

int main()
{
    int s;                   // Socket return value
    struct sockaddr_in sock; // Store the socket IP address

    /* Init socket */
    // Make a call for the socket
    // IPv4 Internet protocol, TCP connection stream, 0 for default protocol
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) // Error handling
    {
        printf("socket() error.\n");
        return -1;
    };

    /* Fill socket address in structure */
    sock.sin_addr.s_addr = inet_addr(IP); // Store IP address of the target
    sock.sin_port = htons(PORT);          // Put in port, htons() converts to network byte order
    sock.sin_family = AF_INET;            // Address family
}