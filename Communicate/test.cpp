#include <exchange.h>
#include <cassert>
#include <cerrno>
#include <cstring>
#include <poll.h>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define MAX_RCVDATA_LEN	8

int unix_create_socket(char *localname);
int unix_sendto(unsigned int sockfd, char *remotename, char *data, int len);

int main(int argc, char**argv)
{
	if(argc != 3) {
		printf("Usage: ./main number1 number2\n");
		return 0;
	}
	int type = atoi(argv[1]);
	int value = atoi(argv[2]);
	char data[8];
	memcpy(&data[0], &type, sizeof(int));
	memcpy(&data[4], &value, sizeof(int));
	int sockfd = unix_create_socket((char*)".unix_send");
	int ret = unix_sendto(sockfd, (char*)UNIX_RCV_ADDR, data, 8);
	printf("ret = %d\n", ret);
	if(ret < 0) {
		printf("Error: %s\n", strerror(errno));
	}
	usleep(500 * 1000);
	return 0;
}

int unix_create_socket(char *localname)
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

int unix_sendto( unsigned int sockfd, char *remotename, char *data, int len )
{
	struct sockaddr_un  remoteaddr;
	int ret_value = 0;
	socklen_t addrlen = 0;

	memset( &remoteaddr, 0x00, sizeof( remoteaddr ) );
	remoteaddr.sun_family = AF_LOCAL;
	strcpy( remoteaddr.sun_path,  remotename );
	addrlen = sizeof( remoteaddr );
	ret_value = sendto(sockfd, data, len, 0, ( struct sockaddr * )&remoteaddr, addrlen );
	return ret_value;
}
