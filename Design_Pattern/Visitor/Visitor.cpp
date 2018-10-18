/*#include "Employee.h"
#include "CommonEmployee.h"
#include "Manager.h"
#include "BaseVisitor.h"
#include <vector>


void MockEmployee(vector<CEmployee*> *pvce)
{
	CCommonEmployee *pZhangSan = new CCommonEmployee();
	pZhangSan->SetJob("��дJava���򣬾��Ե����졢�๤�Ӱ��˹�");
	pZhangSan->SetName("����");
	pZhangSan->SetSalary(1800);
	pZhangSan->SetSex(CEmployee::MALE);
	pvce->push_back(pZhangSan);

	CCommonEmployee *pLiSi = new CCommonEmployee();
	pLiSi->SetJob("ҳ����������������̫�������ˣ�");
	pLiSi->SetName("����");
	pLiSi->SetSalary(1900);
	pLiSi->SetSex(CEmployee::FEMALE);
	pvce->push_back(pLiSi);

	CManager *pWangWu = new CManager();
	pWangWu->SetPerformance("�������Ǹ�ֵ�������һ�����ƨѽ");
	pWangWu->SetName("����");
	pWangWu->SetSalary(1900);
	pWangWu->SetSex(CEmployee::FEMALE);
	pvce->push_back(pWangWu);
}

void DoIt()
{
	vector<CEmployee*> vce;//����ָ��
	MockEmployee(&vce);
	vector<CEmployee*>::const_iterator readIt = vce.begin();

	CBaseVisitor visitor;
	for (; readIt != vce.end(); readIt++)
	{
		(*readIt)->Accept(&visitor);
	}
	//cout << "����˾���¹����ܶ��ǣ�" << CConvert::ToString(visitor.GetTotalSalary()).c_str() << endl;

	vector<CEmployee*>::reverse_iterator delIt = vce.rbegin();
	for (; delIt != vce.rend(); delIt++)
	{
		delete (*delIt);
		(*delIt) = NULL;
	}
	vce.clear();
}

int main()
{
	DoIt();
	system("pause");
	return 0;
}*/
#include "Employee.h"
#include "CommonEmployee.h"
#include "Manager.h"
#include "BaseVisitor.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

void MockEmployee(vector<CEmployee*> *pvce)
{
	CCommonEmployee *pZhangSan = new CCommonEmployee();
	pZhangSan->SetJob("��дJava���򣬾��Ե����졢�๤�Ӱ��˹�");
	pZhangSan->SetName("����");
	pZhangSan->SetSalary(1800);
	pZhangSan->SetSex(CEmployee::MALE);
	pvce->push_back(pZhangSan);

	CCommonEmployee *pLiSi = new CCommonEmployee();
	pLiSi->SetJob("ҳ����������������̫�������ˣ�");
	pLiSi->SetName("����");
	pLiSi->SetSalary(1900);
	pLiSi->SetSex(CEmployee::FEMALE);
	pvce->push_back(pLiSi);

	CManager *pWangWu = new CManager();
	pWangWu->SetPerformance("�������Ǹ�ֵ�������һ�����ƨѽ");
	pWangWu->SetName("����");
	pWangWu->SetSalary(1900);
	pWangWu->SetSex(CEmployee::FEMALE);
	pvce->push_back(pWangWu);
}

void DoIt()
{
	vector<CEmployee*> vce;
	MockEmployee(&vce);
	vector<CEmployee*>::const_iterator readIt = vce.begin();

	CBaseVisitor visitor;
	for (; readIt != vce.end(); readIt++)
	{
		(*readIt)->Accept(&visitor);
	}
	cout << "����˾���¹����ܶ��ǣ�" <<visitor.GetTotalSalary() << endl;

	vector<CEmployee*>::reverse_iterator delIt = vce.rbegin();
	for (; delIt != vce.rend(); delIt++)
	{
		delete (*delIt);
		(*delIt) = NULL;
	}
	vce.clear();
}

int main()
{
	DoIt();
	system("pause");
	return 0;
}