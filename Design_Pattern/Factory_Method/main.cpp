#include "IHuman.h"
#include "YellowHuman.h"
#include "WhiteHuman.h"
#include "BlackHuman.h"
#include "SimpleHumanFactory.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;


void DoSimpleFactory()
{
	CSimpleHumanFactory *pSimpleHumanFactory = new CSimpleHumanFactory();
	cout << "----------��һ�����������ģ�������" << endl;
	IHuman *pYellowHuman = pSimpleHumanFactory->CreateHuman("CYellowHuman");
	pYellowHuman->Cry();
	pYellowHuman->Laugh();
	pYellowHuman->Talk();
	delete pYellowHuman;
	cout << "----------�ڶ������������ģ�������" << endl;
	IHuman *pWhiteHuman = pSimpleHumanFactory->CreateHuman("CWhiteHuman");
	pWhiteHuman->Cry();
	pWhiteHuman->Laugh();
	pWhiteHuman->Talk();
	delete pWhiteHuman;
	cout << "----------���������������ģ�������" << endl;
	IHuman *pBlackHuman = pSimpleHumanFactory->CreateHuman("CBlackHuman");
	pBlackHuman->Cry();
	pBlackHuman->Laugh();
	pBlackHuman->Talk();
	delete pBlackHuman;
	
}


int main()
{
	DoSimpleFactory();

	system("pause");
	return 0;
}