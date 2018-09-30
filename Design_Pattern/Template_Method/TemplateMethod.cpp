#include "HummerModel.h"
#include "HummerH1Model.h"
#include "HummerH2Model.h"
#include <crtdbg.h>
int main()
{
	//�ͻ�����H1�ͺţ���ȥ������gan
	CHummerModel *ph1 = new CHummerH1Model();
	ph1->Run();
	delete ph1;

	//�ͻ���H2�ͺţ���ȥ��ˣ��
	CHummerModel *ph2 = new CHummerH2Model();
	ph2->Run();
	delete ph2;

	//�ͻ�����H1�ͺţ���ȥ�����ˣ����Ҳ���������
	CHummerH1Model *ph11 = new CHummerH1Model();
	ph11->SetAlarm(false);
	ph11->Run();
	delete ph11;

	system("pause");

	return 0;
}