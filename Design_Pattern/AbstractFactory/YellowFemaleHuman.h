#pragma once
#include "yellowhuman.h"
class CYellowFemaleHuman :
	public CYellowHuman
{
public:
	CYellowFemaleHuman(void)
	{
		cout << "CYellowFemaleHuman" << endl;
	}
	~CYellowFemaleHuman(void)
	{
		cout << "~CYellowFemaleHuman" << endl;
	}
	void Sex()
	{
		cout << "�û����˵��Ա�ΪŮ..." << endl;
	}
};