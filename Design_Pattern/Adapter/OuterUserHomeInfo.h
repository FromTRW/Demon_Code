#pragma once
#include <iostream>
using namespace std;
class COuterUserHomeInfo
{
public:
	COuterUserHomeInfo(void)
	{
	}
	~COuterUserHomeInfo(void)
	{
	}
	string GetHomeAddress()
	{
		cout << "������Ա���ļ�ͥ��ַ..." << endl;
		return "0";
	}
	string GetHomeTelNumber()
	{
		cout << "Ա���ļ�ͥ�绰��..." << endl;
		return "0";
	}
};