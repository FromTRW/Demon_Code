#include "NewHouseCorp.h"
CNewHouseCorp::CNewHouseCorp(CHouse *pHouse) : CNewCorp(pHouse)//��CNewCorp���������Ϊ����MakeMoney׼��
{
}
CNewHouseCorp::~CNewHouseCorp(void)
{
}
void CNewHouseCorp::MakeMoney()
{
	this->CNewCorp::MakeMoney();
	cout << "���ز���˾׬��Ǯ��..." << endl;
}