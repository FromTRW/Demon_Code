#pragma once
#include "yellowhuman.h"
class CYellowMaleHuman :
	public CYellowHuman
{
public:
	CYellowMaleHuman(void)
	{
		cout << "CYellowMaleHuman" << endl;
	}
	~CYellowMaleHuman(void)
	{
		cout << "~CYellowMaleHuman" << endl;
	}
	void Sex()
	{
		cout << "�û����˵��Ա�Ϊ��..." << endl;
	}
};