#pragma once
#include "whitehuman.h"
class CWhiteFemaleHuman :
	public CWhiteHuman
{
public:
	CWhiteFemaleHuman(void)
	{
		cout << "CWhiteFemaleHuman" << endl;
	}
	~CWhiteFemaleHuman(void)
	{
		cout << "~CWhiteFemaleHuman" << endl;
	}
	void Sex()
	{
		cout << "�ð����˵��Ա�ΪŮ..." << endl;
	}
};