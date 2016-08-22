#include "unp.h"

int
main (int argc, char **argv)
{
	int sockfd;
	int  n;
	char recvline[MAXLINE + 1];
	char buffman[MAXLINE + 1];
	struct sockaddr_in servaddr;

	if (argc != 3)
	{
		err_quit("usage: a.out <IPaddress>");
	}
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		err_sys("socket error");
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));

	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		err_quit("inet_pton error for %s", argv[1]);
	}
	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
	{
		err_sys("connect error");
	}
//
	snprintf(buffman, sizeof(buffman), "GET /index.html HTTP/1.1\r\nHost: www.comp.dit.ie\r\nConnection: close\r\n\r\n", &servaddr);
	Write(sockfd, buffman, strlen(buffman));

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;

		if (fputs(recvline, stdout) == EOF)
		{
			err_sys("fputs error");
		}

	}

//
	if (n < 0)
	{
		err_sys("read error");
	}
	exit(0);
}
