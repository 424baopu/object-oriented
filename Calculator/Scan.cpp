#include "Scan.h"
#include<iostream>
using namespace std;


Scan::Scan()
{
}

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
			do
			{

				number = number + input[i];//将数字存入字符串
				i++;
			} while (input[i] == '.' || input[i] >= '0' && input[i] <= '9');

	        	if (number.size() > 10)
			{
				cout << "error" << endl;
				m_ijudge = 1;//改变m_ijudge值
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
