#include "BranchNode.h"
#include "LeafNode.h"
string GetTreeInfo(CBranchNode * proot)
{
	vector<CCorpNode*> subordinateList = proot->GetSubordinateInfo();//��ȡproot��m_subordinateList
	string info = "";

	vector<CCorpNode*>::const_iterator it = subordinateList.begin();
	for (; it != subordinateList.end(); it++)
	{
		if ((*it)->IsLeaf())
		{
			info.append((*it)->GetInfo());
			info.append("\n");
		}
		else
		{
			info.append((*it)->GetInfo());
			info.append("\n");
			info.append(GetTreeInfo(dynamic_cast<CBranchNode*>(*it)));
		}
	}
	return info;
}


void DoNew()
{
	CBranchNode root("�Դ�", "�ܾ���", 100000);

	CBranchNode devDep("Ǯ��", "�з����ž���", 10000);
	CBranchNode saleDep("���", "���۲��ž���", 20000);
	CBranchNode financeDep("���", "�����ž���", 30000);
	CBranchNode firstDevGroup("����Ҳб", "����һ���鳤", 5000);
	CBranchNode secondDevGroup("�����", "���������鳤", 6000);

	CLeafNode a("a", "������Ա", 2000);
	CLeafNode b("b", "������Ա", 2000);
	CLeafNode c("c", "������Ա", 2000);
	CLeafNode d("d", "������Ա", 2000);
	CLeafNode e("e", "������Ա", 2000);
	CLeafNode f("f", "������Ա", 2000);
	CLeafNode g("g", "������Ա", 2000);
	CLeafNode h("h", "������Ա", 5000);
	CLeafNode i("i", "������Ա", 4000);
	CLeafNode j("j", "������Ա", 5000);
	CLeafNode k("k", "CEO����", 8000);
	CLeafNode zheng("֣����", "�з���������", 20000);

	//����root�����m_subordinateList
	//�Ը�����Ϊ�������������ݿ��Դ���������ı������ʵ��ָ��
	root.Add(&k);//CEO���������ž����һ������
	root.Add(&devDep);
	root.Add(&saleDep);
	root.Add(&financeDep);

	//����devDep�����m_subordinateList
	devDep.Add(&zheng);//��������һ�������������С��
	devDep.Add(&firstDevGroup);
	devDep.Add(&secondDevGroup);

	firstDevGroup.Add(&a);
	firstDevGroup.Add(&b);
	firstDevGroup.Add(&c);
	
	secondDevGroup.Add(&d);
	secondDevGroup.Add(&e);
	secondDevGroup.Add(&f);

	saleDep.Add(&g);
	saleDep.Add(&h);

	financeDep.Add(&i);
	financeDep.Add(&j);

	cout << root.GetInfo().c_str() << endl;
	cout << GetTreeInfo(&root).c_str() << endl;
}


int main()
{
	//ʹ�����ģʽ��ĵ��á�
	DoNew();
	system("pause");
	return 0;
}