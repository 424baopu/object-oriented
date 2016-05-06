#include<iostream>
#include"text.h"
using namespace std;

int main()
{
	double  radius,area;

	cin >> radius;
	if (radius < 0)
	{
		cout << "error" << endl;
		return 0;
	}
	area=count(radius);
	cout << area << endl;

	return 0;
}