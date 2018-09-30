#pragma once
#include<iostream>
using namespace std;
class IHuman
{
public:

	IHuman(void)
	{
		cout << "IHuman����" << endl;
	}

	virtual ~IHuman(void)
	{
		cout << "IHuman����" << endl;
	}

	virtual void Laugh() = 0;
	virtual void Cry() = 0;
	virtual void Talk() = 0;
	virtual void Sex() = 0;
};