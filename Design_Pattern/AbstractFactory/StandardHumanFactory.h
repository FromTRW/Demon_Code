#pragma once
#include "ihumanfactory.h"
#include "IHuman.h"
template<class T>
class CStandardHumanFactory :
	public IHumanFactory
{
public:
	CStandardHumanFactory(void)
	{
		cout << "CStandardHumanFactory" << endl;
	}
	~CStandardHumanFactory(void)
	{
		cout << "~CStandardHumanFactory" << endl;
	}
	IHuman * CreateHuman()
	{
		return new T;//���ݴ����ģ�壬���ش���ĵ�ģ������
	}
};