#include "thread.h"
#include <QDebug>
Thread::Thread()
{
}
void Thread::setParam(QLabel *label, QPushButton *btn, QLineEdit *let, QTcpSocket **socket,int node)
{
	thread_label = label;
	thread_btn = btn;
	thread_let = let;
	thread_socket = socket;
	socket_node = node;

}
void Thread::run()
{

	i = 0;
	qDebug() <<"�����̱߳�ţ�"<<socket_node <<"------�����߳�IDΪ��" << QThread::currentThread() << endl;
	thread_label->setText("�����߳���");
	QString read_cont = (*thread_socket)->readAll();
	while (run_state)
	{
		if ((*thread_socket)->bytesAvailable()>1)
		{
			read_cont = (*thread_socket)->readAll();
			qDebug() << (*thread_socket)->bytesAvailable() << endl;
			qDebug() << read_cont << endl;
			if (read_cont.length() < 20)
			{
				thread_label->setText("�յ���Ϣ" + read_cont);
				read_cont = "";
			}
			if (read_cont == "close\n")
			{
				//(*thread_socket)->close();
				run_state = false;
			}
		}
	}
	qDebug() << "�����߳�" << endl;
}
