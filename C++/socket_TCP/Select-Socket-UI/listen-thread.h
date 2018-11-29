#ifndef THREAD_H
#define THREAD_H
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include <WS2tcpip.h>
#include <WinSock2.H>
#include <iostream>
#include <QString>
#include <QThread>
#include <sstream>
#pragma comment(lib, "ws2_32.lib") 
class ListenThread: public QThread
{
	Q_OBJECT
public:
	ListenThread();
	~ListenThread();
	WSADATA wsaData;
	WORD version = MAKEWORD(2, 2);
	fd_set allSockSet;
	int result;
	QString ip;
	QString port;
	void Send_Content(QString content,int socket_number);
	void run();
signals:
	//�������ã��������յ������ݣ�������ʾ������
	void content_signal(QString str);
	//����1����socket��������������2������socket�ķ���
	void socket_signal(int numb, int type);
};
#endif // THREAD_H