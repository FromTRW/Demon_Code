#pragma once
#include "ihuman.h"
class CYellowHuman :public IHuman
{
public:
	CYellowHuman(void)
	{
		cout << "CYellowHuman" << endl;
	}
	~CYellowHuman(void)
	{
		cout << "~CYellowHuman" << endl;
	}
	void Laugh()
	{
		cout << "��ɫ���ֻ��Ц���Ҹ�ѽ��" << endl;
	}
	void Cry()
	{
		cout << "��ɫ���ֻ��" << endl;
	}
	void Talk()
	{
		cout << "��ɫ���ֻ�˵����һ��˵�Ķ���˫�ֽ�" << endl;
	}
	virtual void Sex() = 0;
};