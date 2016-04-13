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

	stack<double> num;  //运算数字栈 
	stack<string> sign;  //运算符栈 
	queue<string> after; //后缀表达式队列 

	void trans(queue<string>*s);
	double count();

	Calculation();
	~Calculation();
};

