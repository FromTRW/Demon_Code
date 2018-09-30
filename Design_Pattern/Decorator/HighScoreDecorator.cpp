#include "HighScoreDecorator.h"

CHighScoreDecorator::CHighScoreDecorator(ISchoolReport *psr) : CReportDecorator(psr)
{
	cout << "CHighScoreDecorator" << endl;
}
CHighScoreDecorator::~CHighScoreDecorator(void)
{
	cout << "~CHighScoreDecorator" << endl;
}
void CHighScoreDecorator::Report()
{
	this->ReportHighScore();
	this->CReportDecorator::Report();
}
void CHighScoreDecorator::ReportHighScore()
{
	cout << "��ο������������75�� ��ѧ��78�� ��Ȼ��80" << endl;
}