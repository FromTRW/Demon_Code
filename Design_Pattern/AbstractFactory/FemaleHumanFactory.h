#pragma once
#include "standardhumanfactory.h"
template<class T>
class CFemaleHumanFactory :
	public CStandardHumanFactory<T>
{
public:
	CFemaleHumanFactory(void)
	{
		cout << "CFemaleHumanFactory����" << endl;
	}
	~CFemaleHumanFactory(void)
	{
		cout << "CFemaleHumanFactory����" << endl;
	}
	IHuman * CreateYellowHuman()
	{
		return CreateHuman();
	}
	IHuman * CreateWhiteHuman()
	{
		return CreateHuman();
	}

};