#include "ILift.h"
#include "Lift.h"
#include"Context.h"
#include "OpenningState.h"
#include "CloseingState.h"
#include "RunningState.h"
#include "StoppingState.h"
#include <iostream>
using std::cout;
using std::endl;

void DoIt()
{
	//ILift.h, Lift.h, Lift.cpp
	ILift *pLift = new CLift();
	pLift->SetState(ILift::STOPPING_STATE);//���ݵĳ�ʼ������ֹͣ״̬��
	pLift->Open();//�����ǵ����ſ������˽�ȥ
	pLift->Close();//Ȼ������Źر�
	pLift->Run();//��Ȼ�󣬵��������������ϻ�������
	pLift->Stop();//��󵽴�Ŀ�ĵأ�����ͣ����
	delete pLift;
}


void DoNew()
{
	CContext context;
	CCloseingState closeingState;
	context.SetLiftState(&closeingState);
	context.Close();
	context.Open();
	context.Run();
	context.Stop();
}

int main()
{
	cout << "----------ʹ��ģʽ֮ǰ----------" << endl;
	DoIt();
	cout << "----------ʹ��ģʽ֮��----------" << endl;
	DoNew();

	system("pause");

		return 0;
}