/*
FileName��Calculation.cpp
Description:���ն��У�����������
Function List:
void Calculation::trans(queue<string>*s)����׺���ʽת���ɺ�׺���ʽ
double Calculation::count()�����׺���ʽ
*/
#include "Calculation.h"

Calculation::Calculation()
{
}

//תΪ��׺���ʽ
void Calculation::trans(queue<string>*s)
{
	string c;

	while (s->empty() == false)
	{

		//��ȡ���е�һ��Ԫ��
		c = s->front();

		//cΪ�����ʱ�����ж����ȼ����ͻ���ƽ���Ƚ�ջ��Ԫ�ص����������µ�ջ��Ԫ�رȽϣ�ֱ�����ڻ���ջ�ջ��ߡ���������
		if (c == "*" || c == "/")
		{
			while (sign.empty() == false && (sign.top() == "*" || sign.top() == "/"))
			{
				after.push(sign.top());
				sign.pop();
			}
			sign.push(c);
			s->pop();
		}

		if (c == "+" || c == "-")
		{
			while (sign.empty() == false && (sign.top() == "+" || sign.top() == "-" || sign.top() == "*" || sign.top() == "/"))
			{
				after.push(sign.top());
				sign.pop();
			}
			sign.push(c);
			s->pop();
		}

		//Ϊ����ʱ
		if (c == "(")
		{
			//�ж���һ��Ԫ���Ƿ�Ϊ��-���ǵĻ�˵���¸����Ǹ�������׺���ʽѹ��0
			sign.push(c);

			s->pop();
			if (s->front() == "-")
			{
				after.push("0");
			}

		}
		//�����ż������������ѹ���׺���ʽ����������
		if (c == ")")
		{
			while (sign.top() != "(")
			{
				after.push(sign.top());
				sign.pop();
			}
			sign.pop();
			s->pop();
		}

		//����ֱ�ӽ�ջ
		else if (isdigit(c[0]))
		{
			after.push(c);
			s->pop();
		}

	}

	//�����ȫ������׺���ʽ
	while (sign.empty() == false)
	{
		after.push(sign.top());
		sign.pop();
	}

}

double Calculation::count()
{
	string c;
	stringstream ss;

	num.push(0);//���ǵ�һ����Ϊ����
	while (after.empty() == false)
	{
		double flag = 0;//��ÿ��ջ��Ԫ�����¸�Ԫ��������
		c = after.front();

		//Ϊ������Ͱ�ǰ����Ԫ�ص������������㣬�����������ջ��
		if (c == "+")
		{
			double a = num.top();
			num.pop();
			double b = num.top();
			num.pop();
			flag = b + a;
			num.push(flag);
		}

		if (c == "-")
		{
			double a = num.top();
			num.pop();
			double b = num.top();
			num.pop();
			flag = b - a;
			num.push(flag);
		}

		if (c == "*")
		{
			double a = num.top();
			num.pop();
			double b = num.top();
			num.pop();
			flag = b*a;
			num.push(flag);
		}

		if (c == "/")
		{
			double a = num.top();
			num.pop();
			double b = num.top();
			num.pop();
			flag = b / a;
			num.push(flag);
		}

		//����ֱ�Ӵ���ջ��
		else if (isdigit(c[0]))
		{
			double temp;
			ss << c;
			ss >> temp;
			num.push(temp);
			ss.clear();
		}
		after.pop();
	}
	//ջ��Ԫ��Ϊ����������
	return num.top();
}

Calculation::~Calculation()
{
}
