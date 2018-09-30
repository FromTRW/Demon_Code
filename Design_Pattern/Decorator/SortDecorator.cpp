#include "SortDecorator.h"
CSortDecorator::CSortDecorator(ISchoolReport *psr) : CReportDecorator(psr)
{
	cout << "CSortDecorator" << endl;
}
CSortDecorator::~CSortDecorator(void)
{
	cout << "~CSortDecorator" << endl;
}
void CSortDecorator::ReportSort()
{
	cout << "����������38��..." << endl;
}
void CSortDecorator::Report()
{
	this->CReportDecorator::Report();
	this->ReportSort();
}