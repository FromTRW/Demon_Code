#include"Context.h"
#include<iostream>
using namespace std;
COpenningState* CContext::pOpenningState = NULL;
CCloseingState* CContext::pCloseingState = NULL;
CRunningState* CContext::pRunningState = NULL;
CStoppingState* CContext::pStoppingState = NULL;

CContext::CContext(void)
{
	m_pLiftState = NULL;
	pOpenningState = new COpenningState();
	pCloseingState = new CCloseingState();
	pRunningState = new CRunningState();
	pStoppingState = new CStoppingState();
	cout << "CContext" << endl;
}

CContext::~CContext(void)
{
	delete pOpenningState;
	pOpenningState = NULL;
	delete pCloseingState;
	pCloseingState = NULL;
	delete pRunningState;
	pRunningState = NULL;
	delete pStoppingState;
	pStoppingState = NULL;
	cout << "~CContext" << endl;
}

CLiftState * CContext::GetLiftState()
{
	return m_pLiftState;
}

//���ݴ����ָ�룬�ı����ָ���ָ�򣬴Ӷ��жϾ�����÷�����
void CContext::SetLiftState(CLiftState *pLiftState)
{
	//��һ�δ�������ĵ�CCloseingState������CLiftStateat��m_pLiftStateָ��ָ��CCloseingState
	this->m_pLiftState = pLiftState;//�û���ָ��ָ��������󣬵�������ķ���
	this->m_pLiftState->SetContext(this); //���û���CLiftStateat��SetContext��������ʼ��m_pContext��
}

void CContext::Open()
{
	//m_pLiftStateָ��ָ��CCloseingState
	this->m_pLiftState->Open();
	//ִ�����m_pLiftStateָ��ָ��COpenningState
}

void CContext::Close()
{
	//m_pLiftStateָ��ָ��CCloseingState
	this->m_pLiftState->Close();//����CloseingState��Close����
	//ִ�����m_pLiftStateָ��ָ��COpenningState
}

void CContext::Run()
{
	//m_pLiftStateָ��ָ��COpenningState
	this->m_pLiftState->Run();
	//ִ�����m_pLiftStateָ��ָ��CRunningState
}

void CContext::Stop()
{
	//m_pLiftStateָ��ָ��CRunningState
	this->m_pLiftState->Stop();
	//ִ�����m_pLiftStateָ��ָ��CStoppingState
}