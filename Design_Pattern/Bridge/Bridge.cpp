#include "NewHouseCorp.h"
#include "Clothes.h"
#include "IPod.h"
#include "ShanZhaiCorp.h"
#include <iostream>
using std::cout;
using std::endl;

void DoNewRun1()
{
	cout << "----------���ز���˾���������е�----------" << endl;
	CHouse house;
	CNewHouseCorp newHouseCorp(&house);
	newHouseCorp.MakeMoney();
	cout << endl;

	cout << "----------ɽկ��˾���������е�----------" << endl;
	CClothes clothes;
	CShanZhaiCorp shanZhaiCorp(&clothes);
	shanZhaiCorp.MakeMoney();
	cout << endl;
}

void DoNewRun2()
{
	cout << "----------���ز���˾���������е�----------" << endl;
	CHouse house;
	CNewHouseCorp newHouseCorp(&house);
	newHouseCorp.MakeMoney();
	cout << endl;

	cout << "----------ɽկ��˾���������е�----------" << endl;
	CIPod ipod;
	CShanZhaiCorp shanZhaiCorp(&ipod);
	shanZhaiCorp.MakeMoney();
	cout << endl;
}

int main()
{
	//ֻ�����ҹ�˾��һ���Ƿ��ز���˾����һ�ҹ�˾���·�׬Ǯ�������·�
	DoNewRun1();

	//ֻ�����ҹ�˾��һ���Ƿ��ز���˾����һ�ҹ�˾��ipod׬Ǯ������ipod
	DoNewRun2();

	system("pause");
	return 0;
}