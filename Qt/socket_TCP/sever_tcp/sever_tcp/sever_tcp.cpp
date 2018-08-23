#include "sever_tcp.h"
#pragma execution_character_set("utf-8")
sever_tcp::sever_tcp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_server = new QTcpServer();
	m_socket = new QTcpSocket();
	connect(this->m_server, &QTcpServer::newConnection, this, &sever_tcp::Server_New_Connect);
	
}
void sever_tcp::My_Server_Start()
{
	
	if (ui.Server_Start_Bt->text() == "����")
	{
		qDebug() << "����������";
		QHostAddress IP("192.168.1.53");
		quint16 server_port = 8002;
		if (m_server->listen(IP, server_port))
		{
			qDebug() << "��������";
			ui.Server_Start_Bt->setText("�ر�");
		}
		else
		{
			qDebug() << "����ʧ��";
			ui.Server_Start_Bt->setText("����");
		}
		return;
	}
	if (ui.Server_Start_Bt->text() == "�ر�")
	{
		qDebug() << "�ر�����";
		ui.Server_Start_Bt->setText("����");
	}
	return;
}
void sever_tcp::Server_New_Connect()
{
	qDebug() << "�յ�������";
	m_socket = m_server->nextPendingConnection();//��ȡ�ͻ�������
	QObject::connect(m_socket, &QTcpSocket::readyRead, this, &sever_tcp::socket_Read_Data);
	//QObject::connect(m_socket, &QTcpSocket::disconnected, this, &sever_tcp::socket_Disconnect);
}
void sever_tcp::socket_Read_Data()
{
	qDebug() << "������Ϣ";
	QString buffer;
	buffer = m_socket->readAll();
	ui.plainTextEdit->setPlainText(buffer);
}

void sever_tcp::socket_Disconnect()
{
	qDebug() << "�ͻ��˶Ͽ�����";
}

void sever_tcp::My_Send_Info()
{
	qDebug() << "������Ϣ";
	QString buffer = ui.textEdit->toPlainText();
	qint64 writeResult = m_socket->write(buffer.toLatin1()+'\n');
	bool BoolFlush = m_socket->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "������Ϣ�ɹ�";
	}

}
sever_tcp::~sever_tcp()
{
	m_server->close();
	m_server->deleteLater();
}
