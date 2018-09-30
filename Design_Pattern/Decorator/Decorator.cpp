#include "ISchoolReport.h"
#include "FouthGradeSchoolReport.h"

#include "HighScoreDecorator.h"
#include "SortDecorator.h"

void DoIt()
{
	ISchoolReport *psr = new CFouthGradeSchoolReport();
	psr->Report();//���ɼ���
	psr->Sign("����");//�ܿ��ģ���ǩ����
	delete psr;
}
void DoNew()
{
	cout << "----------�ֲ��ֽ���װ��----------" << endl;
	ISchoolReport *psr = new CFouthGradeSchoolReport();//ԭװ�ɼ��� psrָ��CFouthGradeSchoolReport
	ISchoolReport *pssr = new CSortDecorator(psr);//�ּ��˳ɼ�������˵�� pssrָ��CSortDecorator���޸��ุ��CReportDecorator��ָ��
	ISchoolReport *phsr = new CHighScoreDecorator(pssr);//������߷�˵���ĳɼ����� phsrָ��CHighScoreDecorator���޸ĸ���CReportDecorator��ָ��
	//phsrָ��CHighScoreDecorator
	phsr->Report();//���ɼ���
	phsr->Sign("����");//�ܿ��ģ���ǩ����

	cout << "----------װ��˳���Ӱ��----------" << endl;
	delete pssr;
	delete phsr;
	pssr = NULL;
	phsr = NULL;
	//��װ���ĸ�����Ҫ��˳���Ѿ���װ���ڲ�ȷ���ã���һ��Ҫ�������һ��װ�����Ľӿڡ�
	phsr = new CHighScoreDecorator(psr);//������߷�˵���ĳɼ���
	pssr = new CSortDecorator(phsr);//�ּ��˳ɼ�������˵��
	//pssָ��CSortDecorator
	pssr->Report();//���ɼ���
	pssr->Sign("����");//�ܿ��ģ���ǩ����

	delete pssr;
	delete phsr;
	delete psr;
}
int main()
{
	//��װ��֮ǰ�������ü̳еİ취�������м򵥵�����
	DoIt();

	//�������Ҫ���ε���Ŀ̫���أ�����װ�ε���Ŀ���ǹ̶��ģ��̳���Ȼ���ø�����
	DoNew();

	system("pause");

		return 0;
}