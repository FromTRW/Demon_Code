#include "IProject.h"
#include "Project.h"
#include "ProjectIterator.h"

void DoIt()
{
	cout << "----------δʹ�õ���ģʽ----------" << endl;
	vector<IProject*> projectList;

	projectList.push_back(new CProject("�����ս��Ŀ", 10, 100000));
	projectList.push_back(new CProject("Ťתʱ����Ŀ", 100, 10000000));
	projectList.push_back(new CProject("���˸�����Ŀ", 10000, 1000000000));

	for (int i = 4; i < 6; i++)
	{
		string name = "";
		name.append("��");
		char buf[10] = { 0 };
		sprintf_s(buf, "%d", i);
		name.append(buf);
		name.append("����Ŀ");
		projectList.push_back(new CProject(name, i * 5, i * 1000000));
	}

	vector<IProject*>::const_iterator projectIt = projectList.begin();
	for (; projectIt != projectList.end(); projectIt++)
		cout << (*projectIt)->GetProjectInfo().c_str() << endl;

	vector<IProject*>::reverse_iterator projectDelIt = projectList.rbegin();
	for (; projectDelIt != projectList.rend(); projectDelIt++)
	{
		delete (*projectDelIt);
		(*projectDelIt) = NULL;
	}
	projectList.clear();
}


void DoNew()
{
	cout << "----------ʹ�õ���ģʽ----------" << endl;
	IProject *pproject = new CProject();
	pproject->Add("�����ս��Ŀ", 10, 100000);
	pproject->Add("Ťתʱ����Ŀ", 100, 10000000);
	pproject->Add("���˸�����Ŀ", 10000, 1000000000);

	for (int i = 4; i < 6; i++)
	{
		string name = "";
		name.append("��");
		char buf[10] = { 0 };
		sprintf_s(buf, "%d", i);
		name.append(buf);
		name.append("����Ŀ");
		pproject->Add(name, i * 5, i * 1000000);//��������CProject��Add�ķ��������������뵽m_projectList�������У�����IProject��
	}

	IProjectIterator *pprojectIt = pproject->GetIterator();//����ָ��ָ���������CProjectIterator�����ҽ�CProject��m_projectList��ֵ����CProjectIterator��m_projectList
	while (pprojectIt->HasNext())
	{
		IProject *p = dynamic_cast<IProject*>(pprojectIt->Next());//���������е����ݷ�������
		cout << p->GetProjectInfo().c_str() << endl;//�����������CProject�ķ���
	}
	//��������ɾ������ָֹ��Ұָ��
	delete pprojectIt;
	pprojectIt = NULL;
	pproject->Erase();
	delete pproject;
	pproject = NULL;
}


int main()
{
	//ʹ��Iteratorģʽ֮ǰ
	DoIt();

	//ʹ��Iterator
	DoNew();

	system("pause");

	return 0;
}