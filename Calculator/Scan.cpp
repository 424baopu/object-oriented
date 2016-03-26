/***********************************************
FileName：Scan.cpp
Description:接收四则运算表达式，逐个字符扫描这个表达式，将数字和符号提取出来，并存入队列
Function List:
void ToStringQueue(string input);创建队列
queue<string> *GetQueue();返回指向队列的指针
**********************************************/

#include "Scan.h"
#include<iostream>
using namespace std;

Scan::Scan()
{
}

//将四则运算表达式中字母与数字不同处理存入队列
void Scan::ToStringQueue(string input)
{

	string number;//存储数字
	string sign;//存储符号

	for (int i = 0; i < input.size();)
	{
		//如果是符号直接存入字符串并存入队列
		if (input[i]<'0' || input[i]>'9')
		{
			sign = input[i];
			m_que->push(sign);
			i++;
		}

		//是数字
		else
		{
			//直到一个数存完再存进队列
			do
			{

				number = number + input[i];
				i++;
			} while (input[i] == '.' || input[i] >= '0' && input[i] <= '9');

			if (number.size() > 10)
			{
				cout << "error" << endl;
				m_ijudge = 1;//错误情况将不输出，改变m_ijudge的值留作判断
				break;
			}
			else
			{

				m_que->push(number);//数字存入队列
				number = "";        //清空字符串
			}

		}

	}

}

//返回队列指针
queue<string> *Scan::GetQueue()
{
	return m_que;
}

Scan::~Scan()
{
	delete m_que;
}
