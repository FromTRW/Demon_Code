#include "ShanZhaiCorp.h"

CShanZhaiCorp::CShanZhaiCorp(IProduct *pproduct) : CNewCorp(pproduct)
{
}
CShanZhaiCorp::~CShanZhaiCorp(void)
{
}
void CShanZhaiCorp::MakeMoney()
{
	this->CNewCorp::MakeMoney();
	cout << "��׬Ǯѽ..." << endl;
}