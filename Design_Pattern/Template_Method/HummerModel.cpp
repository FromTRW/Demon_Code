#include "HummerModel.h"
CHummerModel::CHummerModel(void)
{
}
CHummerModel::~CHummerModel(void)
{
}
void CHummerModel::Run()
{
	//�ȷ�������
	Start();
	//���濪ʼ����
	EngineBoom();
	//Ȼ��Ϳ�ʼ���ˣ��ܵĹ���������һ������·���Ͱ�����
	if (IsAlarm())
		Alarm();

	//����Ŀ�ĵؾ�ͣ��
	Stop();
}
bool CHummerModel::IsAlarm()
{
	//���ӷ�����Ĭ�������ǻ����
	return true;
}