/*************************************************************************
FileName:Printh.cpp
Description:接收队列并逐个数出
Function List:void queueTraverse(queue<string>*que);
*************************************************************************/

#include "Print.h"
#include<iostream>
using namespace std;

Print::Print()
{
}

//将队列成员一个一个输出
void Print::queueTraverse(queue<string>*que)
{
	int a = que->size();
	for (int i = 0; i < a; i++)
	{
		cout << que->front() << endl;
		que->pop();
	}
}

Print::~Print()
{
}
