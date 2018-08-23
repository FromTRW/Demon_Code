#include <stdio.h>
#include <winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
int main(int argc, char* argv[])
{
	//��ʼ��WSA windows�Դ���socket
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//����������׽���
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	//�������Ҫ��ip�Ͷ˿�
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8889);
	sin.sin_addr.S_un.S_addr = INADDR_ANY; //��������ĵ�ַ
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) //��������׽����������ip�Ͷ˿ڰ� 
	{
		printf("bind error !");
	}

	//��ʼ����
	if (listen(slisten, 5) == SOCKET_ERROR)  //��listen���� ����ǰ��󶨺õ�slisten�׽���
	{
		printf("listen error !");
		return 0;
	}

	//ѭ����������
	SOCKET sClient;  //�������ӵ��׽���
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr); //���ڽ��ܿͻ��˵�ַ
	char revData[255]; //�洢���ܵ�����
	while (1)
	{
		printf("�ȴ�����...\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen); //�Ϳͻ��� connect������Ӧ
		if (sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}
		char sendBuf[20] = { '\0' };
		printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntop(AF_INET, (void*)&remoteAddr.sin_addr, sendBuf, 16));

		cout << "������Ϣ"<< endl;
		const char *sendData = "hello,TCP Client";
		send(sClient, sendData, strlen(sendData), 0);

		//���ݽ���
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			printf(revData);
		}

		//�������ݸ��ͻ���

		closesocket(sClient);  //�ر��ѽ�ͨ���׽���
	}


	closesocket(slisten); //�رռ������׽���
	WSACleanup();
	return 0;
}