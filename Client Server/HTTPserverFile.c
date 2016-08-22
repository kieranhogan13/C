
#include	"unp.h"
#include 	<string.h>
#include	<stdio.h>

int main(int argc, char **argv)
{
	int listenfd, connfd, n, c; 
	int counter = 0;
	struct sockaddr_in servaddr;
	char buff[MAXLINE], recvline[MAXLINE], buffhead[MAXLINE], cmd[16], path[64], vers[16];
	char path1[64] = ".";

	FILE * pFile;

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
		memset(buff,0,MAXLINE);
		connfd = Accept(listenfd, (SA *) NULL, NULL);
		while ((n = read(connfd, recvline, MAXLINE)) > 0)
		{
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

		sscanf(recvline, "%s %s %s", cmd, path, vers);

		strcpy(path1,".");
 		strcat(path1, path);
		pFile = fopen (path1, "r");
		strcpy(buffhead, "HTTP/1.1200 OK\r\nServer: HTTPserver/1.1Connection: close \r\n\r\n");
		if (pFile != NULL)
		{
			while(1)
			{
				c = fgetc(pFile);
				buff[counter] =(char)c;
				if(c == EOF)
				{
					break;
				}
				counter ++;
			}
			buff[counter] = 0;
			strcat(buffhead,buff);
		}
		else
		{
			strcpy(buffhead, "HTTP/1.1404 ERROR\r\nServer: HTTPserver/1.1Connection: close \r\n\r\n");
			pFile = fopen ("./error.html", "r");
			while(1)
                        {
                                c = fgetc(pFile);
                                buff[counter] = (char)c;
				if(c == EOF)
				{
					break;
				}
				counter ++;
                        }
			buff[counter] = 0;
		}
		Write(connfd, buffhead, strlen(buffhead));
		Close(connfd);
                strcpy(path1,".");
		counter=0;
		fclose(pFile);
	}
}
