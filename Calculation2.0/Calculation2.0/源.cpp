/***************************************************************************************************
FileName:Դ.cpp
Author:424baopu
Date:2015
Description:��������������ʽ��Scan�ദ�������ַ�����������У�Calculation����ն��в�����������
***************************************************************************************************/

#include"Scan.h"
#include"Calculation.h"
#include<cstdio>
#include<cctype>
#include<iostream>
#include<string>
#include<queue>
using namespace std;


int main(int argc, char* argv[])
{
	string input;
	string output;

	int temp = 0;//�ж��Ƿ��С�-a��
	int i;

	Scan sca;
	Calculation calcul;

	for (i = 1; i < argc; i++)
	{
		input = argv[i];
		if (input == "-a")
		{
			temp = 1;
			continue;
		}

	}

	sca.ToStringQueue(input);
	queue<string>*q = sca.GetQueue();//�������ָ����ն���

	//������ַ���Ҫ������� 
	if (sca.m_ijudge == 0)
	{
		if (temp == 1)
		{
			cout << input << "= ";
		}
		calcul.trans(q);
		double result = calcul.count();
		cout << result << endl;

	}
	else
	{
		return 0;
	}

	system("pause");
	return 0;
}
