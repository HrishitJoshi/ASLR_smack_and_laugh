#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SA struct sockaddr

int listenfd, connfd;

void function(char∗ str) {
	char readbuf[256];
	char writebuf[256];
	strcpy(readbuf, str);
	sprintf(writebuf, readbuf);
	write(connfd, writebuf, strlen(writebuf));
}


int main(int argc, char∗ argv[]) {
	char line[1024];
	struct sockaddr_in servaddr;
	ssize_t n;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.saddr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(7776);
	bind(listenfd, (SA∗)&servaddr, sizeof(servaddr));
	listen(listenfd, 1024);
	for(;;) {
		connfd = accept(listenfd, (SA∗)NULL, NULL);
		write(connfd , ”>”, 2);
		n = read(connfd, line, sizeof(line)−1);
		line[n] = 0;
	function(line);
	close(connfd);
}
}