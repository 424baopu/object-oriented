/*
FileName：Calculation.cpp
Description:接收队列，返回运算结果
Function List:
void Calculation::trans(queue<string>*s)将中缀表达式转换成后缀表达式
double Calculation::count()计算后缀表达式
*/
#include "Calculation.h"

Calculation::Calculation()
{
}

//转为后缀表达式
void Calculation::trans(queue<string>*s)
{
	string c;

	while (s->empty() == false)
	{

		//读取队列第一个元素
		c = s->front();

		//c为运算符时，先判断优先级，低活着平级先将栈顶元素弹出，再与新的栈顶元素比较，直到高于或者栈空或者“（”进入
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

		//为括号时
		if (c == "(")
		{
			//判断下一个元素是否为“-”是的话说明下个数是负数，后缀表达式压入0
			sign.push(c);

			s->pop();
			if (s->front() == "-")
			{
				after.push("0");
			}

		}
		//将括号间运算符弹出并压入后缀表达式，括号舍弃
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

		//数字直接进栈
		else if (isdigit(c[0]))
		{
			after.push(c);
			s->pop();
		}

	}

	//运算符全部进后缀表达式
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

	num.push(0);//考虑第一个数为负数
	while (after.empty() == false)
	{
		double flag = 0;//存每次栈顶元素与下个元素运算结果
		c = after.front();

		//为运算符就把前两个元素弹出来参与运算，并将结果存入栈中
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

		//数字直接存入栈中
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
	//栈顶元素为最终运算结果
	return num.top();
}

Calculation::~Calculation()
{
}
