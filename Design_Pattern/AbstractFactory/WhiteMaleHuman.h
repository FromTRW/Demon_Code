#pragma once
#include "whitehuman.h"
class CWhiteMaleHuman :
	public CWhiteHuman
{
public:
	CWhiteMaleHuman(void)
	{
		cout << "CWhiteMaleHuman" << endl;
	}
	~CWhiteMaleHuman(void)
	{
		cout << "~CWhiteMaleHuman" << endl;
	}
	void Sex()
	{
		cout << "�ð����˵��Ա�Ϊ��..." << endl;
	}
};