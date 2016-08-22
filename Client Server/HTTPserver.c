#include	"unp.h"
#include 	<time.h>
#include 	<string.h>
#define		HOME_PAGE "<html>This is HTML code</html>"
#define		ERROR_PAGE "This is a HTTP error message\r\n"

int main(int argc, char **argv)
{
	int listenfd, connfd, n;
	struct sockaddr_in servaddr;
	char buff[MAXLINE], recvline[MAXLINE], cmd[16], path[64], vers[16];
	char html[64] = "/index.html";

	if (argc != 2)
	{
		err_quit("usage: <Program Name> <Port No.>");
	}

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	Listen(listenfd, LISTENQ);

	for ( ; ; )
	{
		connfd = Accept(listenfd, (SA *) NULL, NULL);
		while ((n = read(connfd, recvline, MAXLINE)) > 0)
		{
			sscanf(recvline, "%s %s %s", cmd, path, vers);
			recvline[n] = 0;
			if (fputs(recvline, stdout) == EOF)
			{
				err_sys("fputs error");
			}
			if (strstr (recvline, "\r\n\r\n") > 0)
			{
				break;
			}
		}
		if (strcmp(path, html) == 0)
		{
			snprintf(buff, sizeof(buff), HOME_PAGE);
		}
		else
		{
			snprintf(buff, sizeof(buff), ERROR_PAGE);
		}
		Write(connfd, buff, strlen(buff));
		Close(connfd);
	}
}
