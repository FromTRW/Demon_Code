// halcon1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "HalconCpp.h"  
using namespace HalconCpp;

int _tmain(int argc, _TCHAR* argv[])
{
	HImage img;
	ReadImage(&img, "D:/work/C++/halcon1/halcon1/1.jpg");
	Hlong width, height;
	WriteImage(img, "bmp", 0, "threshold1.bmp");
	img.GetImageSize(&width, &height);
	HWindow w(0, 0, width,height);
	img.DispImage(w);
	w.Click();
	w.ClearWindow();
	return 0;
}

