#include"Scan.h"
#include"Print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
	string s;
	cin >> s;//输入字符串s

	Scan sca;
	sca.ToStringQueue(s);
	queue<string>*q = sca.GetQueue();

	//如果数字符合要求才输出
	if (sca.m_ijudge == 0)
	{
		Print pri;
		pri.queueTraverse(q);
	}

    system("pause");
	return 0;
}
