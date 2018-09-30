#include "IWomen.h"
#include "Women.h"
#include "Handler.h"
#include "Father.h"
#include "Husband.h"
#include "Son.h"
void DoNew()
{
	cout << "----------ʹ��ģʽ��Ĵ���ʽ----------" << endl;
	//Handler.h, Handler.cpp, IWomen.h, Women.h, Women.cpp, Father.h, Father,cpp, Husband.h, Husband.cpp, Son.h, Son.cpp
	IWomen *pwomen1 = new CWomen(1, "��Ҫ��ȥ���");//Ů��
	IWomen *pwomen2 = new CWomen(2, "��Ҫ��ȥ�Է�");//����
	IWomen *pwomen3 = new CWomen(3, "��ҲҪ��ȥ�Է�");//ĸ��
	IWomen *pwomen4 = new CWomen(4, "��ҲҪ��ȥ���");

	CHandler *pfather = new CFather();//ָ���������CFather
	CHandler *phusband = new CHusband();//ָ���������CHusband
	CHandler *pson = new CSon();//ָ���������CSon

	pfather->SetNext(phusband);//����CHandler��SetNext����m_pNextHandlerָ��CHusband
	phusband->SetNext(pson);//����CHandler��SetNext����m_pNextHandlerָ��CSon

	pfather->HandleMessage(pwomen1);
	pfather->HandleMessage(pwomen2);
	pfather->HandleMessage(pwomen3);
	pfather->HandleMessage(pwomen4);

	delete pfather;
	delete phusband;
	delete pson;
	delete pwomen1;
	delete pwomen2;
	delete pwomen3;
	delete pwomen4;
}
int main()
{
	//Ҫʵ���߼��жϣ���Ů�Ե������ȷ��͵������࣬������һ�����Լ�Ҫ����ģ��ͻ�Ӧ���д������Ů���Ѿ������ˣ��ǾͰ��������ת����Ů����CHusband�����������������ƣ��γ���һ����������
	DoNew();
	system("pause");
	return 0;
}