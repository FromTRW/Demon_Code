//������Խӿ���
#pragma once
#include<iostream>
using namespace std;
class IStrategy1
{
	public:
		IStrategy1();
		virtual ~IStrategy1();
		virtual void Operator(void) = 0;
};