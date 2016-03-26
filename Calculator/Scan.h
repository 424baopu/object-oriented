#pragma once
#include<string>
#include<queue>
using namespace std;

class Scan
{
public:
	void ToStringQueue(string input);
	queue<string> *GetQueue();
	int m_ijudge = 0;

	Scan();
	~Scan();
private:
	queue<string>*m_que = new queue<string>;
};

