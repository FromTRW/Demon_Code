#include<iostream>

#include<afx.h>
using namespace std;
void Format()
{
	CString cstr;
	int Value = 1234;
	cstr.Format("XR2.1=%06d", Value);//��ʽ�����������6λ�Ĳ���
	cout << cstr << endl;
	cout << cstr.GetLength() << endl;
}
int main()
{
	Format();
	system("pause");
	return 0;
}