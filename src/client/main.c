/**
 * The main file for the client.
 * @authors Florent Denef, Thomas Ducrot
 */

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* For memset */
#include <sys/socket.h> /* for sockaddr_in and socket() */
#include <arpa/inet.h> /* for htons, inet_pton */
#include "../tools_error.h"

/* args : ip_address_from_viewer udp_port tcp_port */
int main(int argc, char* argv[])
{
	int32_t sockfd = 0;
	int16_t udpPort, tcpPort;
	struct sockaddr_in viewerAddress; /* Client = 1 socket for both, but server = 2 */
	if (argc != 4)
	{
		fprintf(stderr, "Error, args number wrong.\n");
		exit(EXIT_FAILURE);
	}
	udpPort = atoi(argv[2]), tcpPort = atoi(argv[3]);
	memset(&viewerAddress, 0, sizeof(struct sockaddr_in));
	viewerAddress.sin_family = AF_INET;
	viewerAddress.sin_port = htons(udpPort);
	error_errno(inet_pton(AF_INET, argv[1], &viewerAddress.sin_addr));
	error_errno(sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP));
	/* Socket created, now time for work */
}
