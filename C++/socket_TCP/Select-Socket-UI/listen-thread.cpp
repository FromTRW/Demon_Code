#include"listen-thread.h"
ListenThread::ListenThread()
{

}
ListenThread::~ListenThread()
{

}
void ListenThread::Send_Content(QString content,int socket_number)
{
	for (int i = 0; i < allSockSet.fd_count; i++)
	{
		if (socket_number == allSockSet.fd_array[i])
		{
			char*  ch;
			content.append("\n");
			QByteArray ba = content.toLatin1(); // must
			ch = ba.data();
			int nRet = send(allSockSet.fd_array[i], ch, strlen(ch) + 1, 0);
		}
	}
	//char* buf = Send_Content(bufRecv);
	//int nRet = send(socket, buf, strlen(buf) + 1, 0);
}
void ListenThread::run()
{
	result = WSAStartup(version, &wsaData);
	if (result != 0)
	{
		emit content_signal("WSAStartup() error.");
	}

	/// ����������ͨ�е�socket 
	SOCKET socketListen;
	socketListen = socket(AF_INET, SOCK_STREAM, 0);
	if (socketListen == INVALID_SOCKET)
	{
		WSACleanup();
		emit content_signal("socket() error.");
	
	}

	/// ��������ַ�ṹ 
	sockaddr_in svrAddress;
	svrAddress.sin_family = AF_INET;
	char* ip_address;
	QByteArray ba = ip.toLatin1(); // must
	ip_address = ba.data();
	svrAddress.sin_addr.s_addr = inet_addr(ip_address);
	svrAddress.sin_port = htons(port.toInt());

	/// �󶨷������׽��� 
	result = bind(socketListen, (sockaddr*)&svrAddress, sizeof(svrAddress));
	if (result == SOCKET_ERROR)
	{
		closesocket(socketListen);
		WSACleanup();
		emit content_signal("bind() error.");
	
	}

	/// ��������
	result = listen(socketListen, 5);
	if (result == SOCKET_ERROR)
	{
		closesocket(socketListen);
		WSACleanup();
		emit content_signal("listen() error.");
		
	}
	emit content_signal("�����������ɹ��������˿ڣ�");

	//FD_CLR(s, *set); ��set������ɾ��s�׽��֡�
	//FD_ISSET(s, *set); ���s�Ƿ�Ϊset���ϵĳ�Ա��
	//FD_SET(s, *set); ���׽��ּ��뵽set�����С�
	//FD_ZERO(*set); ��set���ϳ�ʼ��Ϊ�ռ��ϡ�

	// selectģ�� 
	allSockSet;//�����׽��ּ��Ͻṹ��
	FD_ZERO(&allSockSet);//��ʼ���׽��ֽṹ��


	struct timeval timeout;//select�����ȴ���ʱ����
	timeout.tv_sec = 1;//���ӳ�ʱ����λ��
	timeout.tv_usec = 0;//�ȴ���ʱ����λ����

	FD_SET(socketListen, &allSockSet); // ��socketListen�����׽��ּ����� 

	while (true)
	{
		fd_set readSet;//���������ȡ��Ϣ�Ľṹ��
		FD_ZERO(&readSet);
		readSet = allSockSet;
		//����1�������ԡ�����0���ɣ�����2���ɶ��׽��ּ��Ͻṹ�壬����3����д�׽��ּ��Ͻṹ�壬����4�������׽��ּ��Ͻṹ�壬����5���ȴ���ʱʱ��
		result = select(0, &readSet, NULL, NULL, NULL);//���readSet�����и����׽���״̬�Ƿ��иı�,û״̬�任����һֱ�ȴ����б仯������ִ�У��޸�ÿ��fd_set�ṹ,ɾ�������ڵĻ�û�����IO�������׽��֡�
		if (result == SOCKET_ERROR)
		{
			emit content_signal("listen() error.");
			break;
		}

		if (FD_ISSET(socketListen, &readSet))
		{
			sockaddr_in clientAddr;
			int len = sizeof(clientAddr);

			SOCKET clientSocket = accept(socketListen, (sockaddr*)&clientAddr, &len);//��ȡ�������ӵ��׽���
			if (clientSocket == INVALID_SOCKET)
			{
				emit content_signal("accept() error.");
				break;
			}
			FD_SET(clientSocket, &allSockSet);// ���´������׽��ּ��뵽������ 

			char ipAddress[16] = { 0 };
			inet_ntop(AF_INET, &clientAddr, ipAddress, 16);
			QString content("���µ�����[");
			content.append(ipAddress);
			content.append(":");
			QString port = QString::number(ntohs(clientAddr.sin_port));
			content.append(port);
			content.append("], Ŀǰ�ͻ��˵�����Ϊ��");
			QString fd_counts = QString::number(allSockSet.fd_count - 1);
			content.append(fd_counts);
			emit content_signal(content);
			emit socket_signal(clientSocket,1);
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
						QString content("�ͻ���[");
						content.append(ipAddress);
						content.append(":");
						QString port = QString::number(ntohs(clientAddr.sin_port));
						content.append(port);
						content.append("]��ǿ�йر�,");
						emit content_signal(content);
						
					}
					else
					{
						emit content_signal("recv() error��");
						std::cout << "recv() error��" << std::endl;
					}

					closesocket(socket);
					FD_CLR(socket, &allSockSet);
					QString content("Ŀǰ�ͻ��˵�����Ϊ��");
					
					QString fd_count = QString::number(allSockSet.fd_count - 1);
					content.append(fd_count);
					emit content_signal(content);
					emit socket_signal(socket, -1);
					break;
				}
				else if (result == 0)				/// �ͻ��˵�socket����closesocket�����ر�
				{
					closesocket(socket);
					FD_CLR(socket, &allSockSet);
					allSockSet.fd_array[i] = 0;
					QString content("�ͻ���[");
					content.append(ipAddress);
					content.append(":");

					
					QString port=QString::number( ntohs(clientAddr.sin_port));
					content.append("]�Ѿ��˳���Ŀǰ�ͻ��˵�����Ϊ��");
					QString fd_count = QString::number(allSockSet.fd_count - 1);
					content.append(fd_count);
					emit content_signal(content);
					emit socket_signal(socket, -1);
					break;
				}

				bufRecv[result] = '\0';
				QString content("���Կͻ���[");
				content.append(ipAddress);
				
				QString port=QString::number(ntohs(clientAddr.sin_port));
				content.append(port);
				content.append("]����Ϣ��");
				content.append(bufRecv);
				emit content_signal(content);

			}
		}
	}

	for (u_int i = 0; i < allSockSet.fd_count; ++i)
	{
		SOCKET socket = allSockSet.fd_array[i];
		closesocket(socket);
	}

	WSACleanup();
}