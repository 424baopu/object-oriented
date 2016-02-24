#include "Scan.h"
#include<iostream>
using namespace std;


Scan::Scan()
{
}

void Scan::ToStringQueue(string input)
{
	
	string number;//�洢����
	string sign;//�洢����
	
	for (int i = 0; i < input.size();)
	{
		//����Ƿ���ֱ�Ӵ����ַ������������
		if (input[i]<'0' || input[i]>'9')
		{
			sign = input[i];
			m_que->push(sign);
			i++;
		}
		
		//������
		else
		{
			do
			{

				number = number + input[i];//�����ִ����ַ���
				i++;
			} while (input[i] == '.' || input[i] >= '0' && input[i] <= '9');

			if (number.size() > 10)
			{
				cout << "error" << endl;
				break;
			}
			else
			{

				m_que->push(number);//���ִ������
			    number = "";        //����ַ���
			}
			
		}
		
	}

}

//���ض���ָ��
queue<string> *Scan::GetQueue()
{
	return m_que;
}

Scan::~Scan()
{
	delete m_que;
}
