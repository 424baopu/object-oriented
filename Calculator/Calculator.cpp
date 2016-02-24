#include"Scan.h"
#include"Print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
	string s;
	cin >> s;//ÊäÈë×Ö·û´®s

	Scan sca;
	sca.ToStringQueue(s);
	queue<string>*q = sca.GetQueue();

	Print pri;
	pri.queueTraverse(q);

    system("pause");
	return 0;
}