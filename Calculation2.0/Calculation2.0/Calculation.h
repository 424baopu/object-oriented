#pragma once

#include<string> 
#include<stack>
#include<queue>
#include<sstream>
#include <iostream>
using namespace std;

class Calculation
{
public:

	stack<double> num;  //��������ջ 
	stack<string> sign;  //�����ջ 
	queue<string> after; //��׺���ʽ���� 

	void trans(queue<string>*s);
	double count();

	Calculation();
	~Calculation();
};

