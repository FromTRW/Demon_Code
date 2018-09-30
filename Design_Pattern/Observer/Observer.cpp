#include "HanFeiziObservable.h"
#include "LiSiObserver.h"
#include "ZhouSiObserver.h"

void DoNew()
{
	//IHanFeiZi.h, HanFeiZiNew.h, ILiSi.h, LiSi.h
	// cout << "----------���µķ�������----------" << endl;

	//CHanFeiZiNew hanfeizi;

	//hanfeizi.HaveBreakfast();

	//hanfeizi.HaveFun();
}


void DoNewNew()
{
	//IObservable.h, HanfeiziObservable.h, IObserver.h, LiSiObserver.h
	cout << "----------�ø��µķ���������----------" << endl;
	IObserver *pLiSi = new CLiSiObserver();//ָ��CLiSiObserver
	IObserver *pZhouSi = new CZhouSiObserver();//ָ��CLiSiObserver

	CHanFeiziObservable *pHanFeiZi = new CHanFeiziObservable();

	pHanFeiZi->AddObserver(pLiSi);
	pHanFeiZi->AddObserver(pZhouSi);
	pHanFeiZi->HaveBreakfast();

	pHanFeiZi->DeleteObserver(pLiSi);
	delete pLiSi;
	pLiSi = NULL;
	delete pZhouSi;
	pZhouSi = NULL;
}


int main()
{
	//�Ƚ�ԭʼ�ķ��������߳����۲졣
	//DoIt();

	//����˹�����ۼ���������������ϣ������Ļ���϶�̫���ˣ������ø�����ķ�ʽ��
	DoNew();

	//������ķ�ʽ����Ҫ�۲캫���ӵ��˶���ȥ�ˣ�������ֻ������˹�۲졣
	DoNewNew();

	system("pause");

		return 0;
}