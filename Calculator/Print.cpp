#include "Print.h"
#include<iostream>
using namespace std;

Print::Print()
{
}

void Print::queueTraverse(queue<string>*que)
{
	int a = que->size();
	for (int i = 0; i < a;i++)
	{
		cout << que->front() << endl;
		que->pop();//访问一个出队一个
	}
}

Print::~Print()
{
}
