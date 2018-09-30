#pragma once
#include "ihuman.h"
#include <iostream>
using std::cout;
using std::endl;
class CWhiteHuman :
	public IHuman
{
public:
	CWhiteHuman(void)
	{
		cout << "CWhiteHuman" << endl;
	}
	~CWhiteHuman(void)
	{
		cout << "~CWhiteHuman" << endl;
	}
	void Laugh()
	{
		cout << "��ɫ���ֻ��Ц�����Ե�Ц��" << endl;
	}
	void Cry()
	{
		cout << "��ɫ���ֻ��" << endl;
	}
	void Talk()
	{
		cout << "��ɫ���ֻ�˵����һ�㶼�ǵ��ֽ�" << endl;
	}
	virtual void Sex() = 0;
};