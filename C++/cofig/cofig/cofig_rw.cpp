#include<iostream>
#include<afxwin.h>
#include<string>
using namespace std;

int main()
{
	int m_nTest;
	char m_nstr[20];

	m_nTest = GetPrivateProfileInt("Custom_Config", "m_nTest", 123456, "D:\\work\\C++\\cofig\\cofig\\cofig.ini"); //���û�д������ļ����ҵ�����Ĭ��Ϊ12345
	//m_nstr = GetPrivateProfileInt("Custom_Config", "m_nstr", "123", "D:\\work\\C++\\cofig\\cofig\\cofig.ini");
	GetPrivateProfileString("Custom_Config", "m_nstr","123", m_nstr, sizeof(m_nstr), "D:\\work\\C++\\cofig\\cofig\\cofig.ini");
	cout << m_nTest << endl;
	cout << m_nstr << endl;
	system("pause");
}
