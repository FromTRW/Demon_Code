#include "mmi_server_demon.h"

MMI_Server_Demon::MMI_Server_Demon(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	for (int i = 0; i < 10; i++)
	{
		socket_state[i] = 0;
	}
	
}

void MMI_Server_Demon::My_Server_Start()
{
	if (ui.Server_Start_Bt->text() == "����")
	{
		m_server = new QTcpServer;
		connect(this->m_server, &QTcpServer::newConnection, this, &MMI_Server_Demon::Server_New_Connect);
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
		m_server->close();
		m_server->deleteLater();
		delete m_server;
		m_server = NULL;
	}
	return;
}

void MMI_Server_Demon::Server_New_Connect()
{
	qDebug() << "�յ�������";
	for (int i = 0; i < 10; i++)
	{
		if (socket_state[i] == 0)
		{
			if (i == 0)
			{
				qDebug() << "���豸1�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket1_Disconnect);
				thread[i].setParam(ui.read_1, ui.Send_Bt_1, ui.send_1, &m_socket[i], i);
				thread[0].run_state = true;
				socket_state[i] = 1;
				thread[i].start();
				break;
			}
		
			if (i == 1)
			{
				qDebug() << "���豸2�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				thread[1].run_state = true;
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket2_Disconnect);
				thread[i].setParam(ui.read_2, ui.Send_Bt_2, ui.send_2, &m_socket[i], i);
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 2)
			{
				qDebug() << "���豸3�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket3_Disconnect);
				thread[i].setParam(ui.read_3, ui.Send_Bt_3, ui.send_3, &m_socket[i], i);
				thread[2].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 3)
			{
				qDebug() << "���豸4�����ӽ��д������ҿ����̣߳�" << endl;
				
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket4_Disconnect);
				thread[i].setParam(ui.read_4, ui.Send_Bt_4, ui.send_4, &m_socket[i], i);
				thread[3].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 4)
			{
				qDebug() << "���豸5�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket5_Disconnect);
				thread[i].setParam(ui.read_5, ui.Send_Bt_5, ui.send_5, &m_socket[i], i);
				thread[4].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 5)
			{
				qDebug() << "���豸6�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket6_Disconnect);
				thread[i].setParam(ui.read_6, ui.Send_Bt_6, ui.send_6, &m_socket[i], i);
				thread[5].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 6)
			{

				qDebug() << "���豸7�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket7_Disconnect);
				thread[i].setParam(ui.read_7, ui.Send_Bt_7, ui.send_7, &m_socket[i],i);
				thread[6].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 7)
			{
				qDebug() << "���豸8�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket8_Disconnect);
				thread[i].setParam(ui.read_8, ui.Send_Bt_8, ui.send_8, &m_socket[i], i);
				thread[7].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 8)
			{
				qDebug() << "���豸9�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket9_Disconnect);
				thread[i].setParam(ui.read_9, ui.Send_Bt_9, ui.send_9, &m_socket[i], i);
				thread[8].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}

			if (i == 9)
			{
				qDebug() << "���豸1�����ӽ��д������ҿ����̣߳�" << endl;
				m_socket[i] = m_server->nextPendingConnection();//��ȡ�ͻ�������
				QObject::connect(m_socket[i], &QTcpSocket::disconnected, this, &MMI_Server_Demon::socket10_Disconnect);
				thread[i].setParam(ui.read_10, ui.Send_Bt_10, ui.send_10, &m_socket[i], i);
				thread[9].run_state = true;
				thread[i].start();
				socket_state[i] = 1;
				break;
			}
				
		}
	}
	
	
}

void MMI_Server_Demon::Dev_Send1()
{
	QString send_cont = ui.send_1->text();
	qint64 writeResult = m_socket[0]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[0]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸1������Ϣ�ɹ�";
	}
}
void MMI_Server_Demon::socket1_Disconnect()
{
	qDebug() << "�豸1���ӶϿ�";
	socket_state[0] = 0;
	thread[0].run_state = false;
	ui.read_1->setText("���ӶϿ�");
}

void MMI_Server_Demon::Dev_Send2()
{
	QString send_cont = ui.send_2->text();
	qint64 writeResult = m_socket[1]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[1]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸1������Ϣ�ɹ�";
	}
	
}
void MMI_Server_Demon::socket2_Disconnect()
{
	socket_state[1] = 0;
	thread[0].run_state = false;
	ui.read_2->setText("���ӶϿ�");
}

void MMI_Server_Demon::Dev_Send3()
{
	QString send_cont = ui.send_3->text();
	qint64 writeResult = m_socket[2]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[2]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸3������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket3_Disconnect()
{
	socket_state[2] = 0;
	thread[2].run_state = false;
	ui.read_3->setText("���ӶϿ�");
}

void MMI_Server_Demon::Dev_Send4()
{
	QString send_cont = ui.send_4->text();
	qint64 writeResult = m_socket[3]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[3]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸4������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket4_Disconnect()
{
	socket_state[3] = 0;
	thread[3].run_state = false;
	ui.read_4->setText("���ӶϿ�");
}


void MMI_Server_Demon::Dev_Send5()
{
	QString send_cont = ui.send_5->text();
	qint64 writeResult = m_socket[4]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[4]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸1������Ϣ�ɹ�";
	}
}
void MMI_Server_Demon::socket5_Disconnect()
{
	socket_state[4] = 0;
	thread[4].run_state = false;
	ui.read_5->setText("���ӶϿ�");
}


void MMI_Server_Demon::Dev_Send6()
{
	QString send_cont = ui.send_6->text();
	qint64 writeResult = m_socket[5]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[5]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸1������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket6_Disconnect()
{
	socket_state[5] = 0;
	thread[5].run_state = false;
	ui.read_6->setText("���ӶϿ�");
}


void MMI_Server_Demon::Dev_Send7()
{
	QString send_cont = ui.send_7->text();
	qint64 writeResult = m_socket[6]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[6]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸7������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket7_Disconnect()
{
	socket_state[6] = 0;
	thread[6].run_state = false;
	ui.read_7->setText("���ӶϿ�");
}


void MMI_Server_Demon::Dev_Send8()
{
	QString send_cont = ui.send_8->text();
	qint64 writeResult = m_socket[7]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[7]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸8������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket8_Disconnect()
{
	socket_state[7] = 0;
	thread[7].run_state = false;
	ui.read_8->setText("���ӶϿ�");
}


void MMI_Server_Demon::Dev_Send9()
{
	QString send_cont = ui.send_9->text();
	qint64 writeResult = m_socket[8]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[8]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸9������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket9_Disconnect()
{
	socket_state[8] = 0;
	thread[8].run_state = false;
	ui.read_9->setText("���ӶϿ�");
}

void MMI_Server_Demon::Dev_Send10()
{
	QString send_cont = ui.send_10->text();
	qint64 writeResult = m_socket[9]->write(send_cont.toLatin1() + '\n');
	bool BoolFlush = m_socket[9]->flush();
	if (writeResult != -1 && BoolFlush == 1)
	{
		qDebug() << "�豸10������Ϣ�ɹ�";
	}

}
void MMI_Server_Demon::socket10_Disconnect()
{
	socket_state[9] = 0;
	thread[9].run_state = false;
	ui.read_10->setText("���ӶϿ�");
}

/*DWORD WINAPI MMI_Server_Demon::ThreadProc5()
{
	ui.read_1->setText("windows�߳�");
	return 0;
}*/

MMI_Server_Demon::~MMI_Server_Demon()
{

}
