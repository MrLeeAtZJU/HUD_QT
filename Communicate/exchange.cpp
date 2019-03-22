#include "exchange.h"
#include <cassert>
#include <cerrno>
#include <cstring>
#include <poll.h>
#include <pthread.h>
#include <cstdio>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define MAX_RCVDATA_LEN	8

Exchange::Exchange()
{
	fbContent = NULL;
	refreshUIFun = NULL;
	th_RcvData = 0;
	sockfd = unix_create_socket((char*)UNIX_RCV_ADDR);
	assert(sockfd > 0);
	pthread_create(&th_RcvData, NULL, receiveData, (void*)this);
}

Exchange::~Exchange()
{
	pthread_cancel(th_RcvData);
	pthread_join(th_RcvData, NULL);
	close(sockfd);
	printf("~Exchange()\n");
}

int Exchange::unix_create_socket(char *localname)
{
	int local_sockfd = 0;
	struct sockaddr_un localaddr;

	local_sockfd = socket( AF_LOCAL, SOCK_DGRAM, 0 );
	if( local_sockfd < 0 ) {
		printf("[%s %d]: create unix socket failed: %s\n", __FILE__, __LINE__, strerror(errno));
		return -1;
	}

	unlink( localname );
	memset( &localaddr, 0x00, sizeof(localaddr) );

	localaddr.sun_family = AF_LOCAL;
	strcpy( localaddr.sun_path, localname );

	if( bind(local_sockfd, (struct sockaddr*)&localaddr, sizeof(localaddr)) < 0 ) {
		printf("[%s %d]: bind unix socket failed: %s\n", __FILE__, __LINE__, strerror(errno));
		close(local_sockfd);
		return -1;
	}
	return local_sockfd;
}

void Exchange::RegRefreshUIFunc(RefreshUIFb fb, void* content)
{
	refreshUIFun = fb;
	fbContent = content;
}

void Exchange::refreshUI(int type, int value)
{
	if(refreshUIFun)
		refreshUIFun(type, value, fbContent);
	else
		printf("[%s %d]: refreshUIFun hasn't been registered.\n", __FILE__, __LINE__);
}

void* Exchange::receiveData(void *arg)
{
	Exchange* pEx = (Exchange*)arg;
	char rcvdata[MAX_RCVDATA_LEN];

	struct sockaddr_un remoteaddr;
	socklen_t addrlen = sizeof(remoteaddr);

	struct pollfd pfd[1];
	pfd[0].fd = pEx->sockfd;
	pfd[0].events = POLLIN;
	pfd[0].revents = 0;
	int ret, type, value;

	while(true) {
		ret = poll(pfd, 1, -1);
		if(ret < 0) {
			printf("[%s %d]: poll error: %s\n", __FILE__, __LINE__, strerror(errno));
			pthread_exit((void*)0);
		}
		else if(ret > 0) {
			memset(&remoteaddr, 0x00, sizeof(remoteaddr));
			ret = recvfrom( pEx->sockfd, rcvdata, sizeof(rcvdata), 0, (struct sockaddr*)&remoteaddr, &addrlen );
			if(ret < 0) {
				printf("[%s %d]: recvfrom error: %s\n", __FILE__, __LINE__, strerror(errno));
				pthread_exit((void*)0);
			}
			else {
				memcpy(&type, &rcvdata[0], sizeof(int));
				memcpy(&value, &rcvdata[4], sizeof(int));
				printf("type = %d, value = %d\n", type, value);
				pEx->refreshUI(type, value);
			}
		}
	} /* end of while(true) { */
	pthread_exit((void*)0);
}
