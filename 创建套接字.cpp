#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2,2), &wsaData);

	SOCKET sock =  socket(AF_INET, SOCK_STREAM, 0);
	
	//�ж��Ƿ񴴽��ɹ�
	if (sock == INVALID_SOCKET) {
		printf("�����׽���ʧ�ܡ�\n");
		WSACleanup();
		return 1;
	}

	printf("�ɹ�����һ��tcp�׽��֡�\n");

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(6000);

	//printf("%08x", inet_addr("127.0.0.1"));
	int result = bind(sock, (sockaddr*)&addr, sizeof(addr));
	if(result == SOCKET_ERROR)
{
		printf("��׽���ʧ�ܡ�\n");
		closesocket(sock);
		WSACleanup();
		return 1;
	}

	printf("�ɹ���׽��֡�\n");

	//�ر��׽���
	closesocket(sock);
	WSACleanup();

	system("pause");
	return 0;
}
