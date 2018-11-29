#define  IP_ADDRESS "192.168.1.133"
#include <WS2tcpip.h>
#include <WinSock2.H>
#include <iostream>
#include <string>
#define FD_SETSIZE 12
#pragma comment(lib, "ws2_32.lib") 
char* Send_Content(char* str)
{
	std::string str1(str);
	if (str1=="11\n")
	{
		return "11\n";
	}
	if (str1 == "22\n")
	{
		return "22\n";
	}
	if (str1 == "33\n")
	{
		return "33\n";
	}
}
int main()
{
	/// ��ʼ��socket
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 2);
	int result = 0;
	result = WSAStartup(version, &wsaData);
	if (result != 0)
	{
		std::cout << "WSAStartup() error." << std::endl;
		return -1;
	}

	/// ����������ͨ�е�socket 
	SOCKET socketListen;
	socketListen = socket(AF_INET, SOCK_STREAM, 0);
	if (socketListen == INVALID_SOCKET)
	{
		WSACleanup();
		std::cout << "socket() error." << std::endl;
		return -1;
	}

	/// ��������ַ�ṹ 
	sockaddr_in svrAddress;
	svrAddress.sin_family = AF_INET;
	svrAddress.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	svrAddress.sin_port = htons(8002);

	/// �󶨷������׽��� 
	result = bind(socketListen, (sockaddr*)&svrAddress, sizeof(svrAddress));
	if (result == SOCKET_ERROR)
	{
		closesocket(socketListen);
		WSACleanup();
		std::cout << "bind() error." << std::endl;
		return -1;
	}

	/// ��������
	result = listen(socketListen, 5);
	if (result == SOCKET_ERROR)
	{
		closesocket(socketListen);
		WSACleanup();
		std::cout << "listen() error." << std::endl;
		return -1;
	}
	std::cout << "�����������ɹ��������˿ڣ�" << ntohs(svrAddress.sin_port) << std::endl;
	
	//FD_CLR(s, *set); ��set������ɾ��s�׽��֡�
	//FD_ISSET(s, *set); ���s�Ƿ�Ϊset���ϵĳ�Ա��
	//FD_SET(s, *set); ���׽��ּ��뵽set�����С�
	//FD_ZERO(*set); ��set���ϳ�ʼ��Ϊ�ռ��ϡ�
	
	// selectģ�� 
	fd_set allSockSet;//�����׽��ּ��Ͻṹ��
	allSockSet.fd_count = 3;//���ü��
	FD_ZERO(&allSockSet);//��ʼ���׽��ֽṹ��
	

	struct timeval timeout;//select�����ȴ���ʱ����
	timeout.tv_sec = 0;//���ӳ�ʱ����λ��
	timeout.tv_usec = 100;//�ȴ���ʱ����λ����

	FD_SET(socketListen, &allSockSet); // ��socketListen�����׽��ּ����� 

	while (true)
	{
		fd_set readSet;//���������ȡ��Ϣ�Ľṹ��
		readSet.fd_count = 3;
		FD_ZERO(&readSet);
		
		readSet = allSockSet;
		//����1�������ԡ�����0���ɣ�����2���ɶ��׽��ּ��Ͻṹ�壬����3����д�׽��ּ��Ͻṹ�壬����4�������׽��ּ��Ͻṹ�壬����5���ȴ���ʱʱ��
		result = select(0, &readSet, NULL, NULL, &timeout);//���readSet�����и����׽���״̬�Ƿ��иı�,û״̬�任����һֱ�ȴ����б仯������ִ�У��޸�ÿ��fd_set�ṹ,ɾ�������ڵĻ�û�����IO�������׽��֡�
		if (result == SOCKET_ERROR)
		{
			std::cout << "listen() error." << std::endl;
			break;
		}

		if (FD_ISSET(socketListen, &readSet))
		{
			sockaddr_in clientAddr;
			int len = sizeof(clientAddr);

			SOCKET clientSocket = accept(socketListen, (sockaddr*)&clientAddr, &len);//��ȡ�������ӵ��׽���
			if (clientSocket == INVALID_SOCKET)
			{
				std::cout << "accept() error." << std::endl;
				break;
			}
			FD_SET(clientSocket, &allSockSet);	 /// ���´������׽��ּ��뵽������ 

			char ipAddress[16] = { 0 };
			inet_ntop(AF_INET, &clientAddr, ipAddress, 16);
			std::cout << "���µ�����[" << ipAddress << ":" << ntohs(clientAddr.sin_port)
				<< "], Ŀǰ�ͻ��˵�����Ϊ��" << allSockSet.fd_count - 1 << std::endl;

			continue;
		}

		for (u_int i = 0; i < allSockSet.fd_count; ++i)
		{
			SOCKET socket = allSockSet.fd_array[i];

			sockaddr_in clientAddr;
			int len = sizeof(clientAddr);
			getpeername(socket, (struct sockaddr *)&clientAddr, &len);
			char ipAddress[16] = { 0 };
			inet_ntop(AF_INET, &clientAddr, ipAddress, 16);

			/// �ɶ��Լ��ӣ��ɶ���ָ�����ӵ����������ݵ����������ѹرա����û���ֹ
			if (FD_ISSET(socket, &readSet))
			{
				char bufRecv[100];
				result = recv(socket, bufRecv, 100, 0);
				if (result == SOCKET_ERROR)
				{
					DWORD err = WSAGetLastError();
					if (err == WSAECONNRESET)		/// �ͻ��˵�socketû�б������ر�,��û�е���closesocket
					{
						std::cout << "�ͻ���[" << ipAddress << ":" << ntohs(clientAddr.sin_port) << "]��ǿ�йر�, ";
					}
					else
					{
						std::cout << "recv() error��" << std::endl;
					}

					closesocket(socket);
					FD_CLR(socket, &allSockSet);

					std::cout << "Ŀǰ�ͻ��˵�����Ϊ��" << allSockSet.fd_count - 1 << std::endl;
					break;
				}
				else if (result == 0)				/// �ͻ��˵�socket����closesocket�����ر�
				{
					closesocket(socket);
					FD_CLR(socket, &allSockSet);

					std::cout << "�ͻ���[" << ipAddress << ":" << ntohs(clientAddr.sin_port)
						<< "]�Ѿ��˳���Ŀǰ�ͻ��˵�����Ϊ��" << allSockSet.fd_count - 1 << std::endl;
					break;
				}

				bufRecv[result] = '\0';
				std::cout << "���Կͻ���[" << ipAddress << ":" << ntohs(clientAddr.sin_port)
					<< "]����Ϣ��" << bufRecv << std::endl;
				char* buf = Send_Content(bufRecv);
				int nRet = send(socket, buf, strlen(buf) + 1, 0);

			}
		}
	}

	for (u_int i = 0; i < allSockSet.fd_count; ++i)
	{
		SOCKET socket = allSockSet.fd_array[i];
		closesocket(socket);
	}

	WSACleanup();
	return 0;
}