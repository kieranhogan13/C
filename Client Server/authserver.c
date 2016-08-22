#include	"unp.h"
#include 	<string.h>

int main(int argc, char **argv)
{
	int listenfd, connfd, n;
	struct sockaddr_in servaddr;
	char wbuff[MAXLINE], rbuff[MAXLINE];
	char usernameBuff[MAXLINE], passwordBuff[MAXLINE];

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
		while ((n = read(connfd, rbuff, MAXLINE)) > 0)
		{

			rbuff[n] = 0;
			if (fputs(rbuff, stdout) == EOF)
			{
				err_sys("fputs error");
			}
			if (strstr (rbuff, "\r\n\r\n") > 0)
			{
				break;
			}
		}
		sscanf(rbuff, "%s %s", usernameBuff, passwordBuff);

		if (strcmp(usernameBuff, "admin") == 0)
		{
			if (strcmp(passwordBuff, "pass") == 0)
			{
				snprintf(wbuff, sizeof(wbuff), "GRANTED\r\n");
			}
			else
			{
				snprintf(wbuff, sizeof(wbuff), "DENIED\r\n");
			}
		}
		else
		{
			snprintf(wbuff, sizeof(wbuff), "DENIED\r\n");
		}
		Write(connfd, wbuff, strlen(wbuff));
		Close(connfd);
	}
}
