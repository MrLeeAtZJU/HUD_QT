#pragma once

#define UNIX_RCV_ADDR	".unix_receive"
using RefreshUIFb = void (*)(int type, int value, void* ptr);

class Exchange {
public:
	Exchange();
	~Exchange();
	void RegRefreshUIFunc(RefreshUIFb fb, void* content);
	void refreshUI(int type, int value);
private:
	int unix_create_socket(char *localname);
	static void *receiveData(void *arg);
private:
	int sockfd;
	RefreshUIFb refreshUIFun;
	void *fbContent;
	unsigned long int th_RcvData;
};
