#pragma once
#include<iostream>
using namespace std;
class COuterUserBaseInfo
{
public:
	COuterUserBaseInfo(void)
	{
	}
	~COuterUserBaseInfo(void)
	{
	}
	string GetUserName()
	{
		cout << "��������..." << endl;
		return "0";
	}
	string GetMobileNumber()
	{
		cout << "�����outer���ֻ�������... " << endl;
		return "0";
	}
};