#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	int i = 0;
	while (i<10)
	{
		cout << "������aֵ:";
		cin >> a;
		cout << "������bֵ:";
		cin >> b;
		cout << "������cֵ:";
		cin >> c;
		cout << "������dֵ:";
		cin >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)
		{
			cout << "����������"<<endl;
			continue;
		}
		else if (a == 1)
		{
			cout << "a������" << endl;
		}
		else if (b == 1)
		{
			cout << "b������" << endl;
		}
		else if (c == 1)
		{
			cout << "c������" << endl;
		}
		else if (d == 1)
		{
			cout << "d������" << endl;
		}
		else
		{
			cout << "ֱ�ӽ���" << endl;
			return 0;
		}
		cout << i << "�δ�����" << endl;
		i = i + 1;
	}
	system("pause");
	return 0;
}