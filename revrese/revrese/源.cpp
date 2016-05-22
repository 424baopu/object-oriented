#include<iostream>
#include<cstdio>
using namespace std;

struct Node
{
	int address;
	int date;
	int next;
	Node *Next;
};

struct Node node[100010];
int num = 0;//记录有效节点个数

Node *create(int first)//创建链表
{
	Node*head, *p1, *p2;
	p1 = &node[first];
	head = p1;
	num++;
	while (p1->next != -1)
	{
		p2 = p1;
		p1 = &node[p1->next];
		p2->Next = p1;
		num++;
	}
	p1->Next = NULL;
	return head;
}

Node *reverse(Node *head, int k, int num)
{
	Node *p;
	Node *p1, *p2, *p3;//p1需要反转的点，p2反转点插入位置后面一个点，p3反转点插入位置的前一个点
	int i;

	p = p1 = p3 = head;
	p2 = p;

	for (i = 0; i < num; i++)
	{
		int j = 1;
		while (j != k)
		{
			p1 = p->Next;
			p->Next = p1->Next;
			p->next = p1->next;

			if (i == 0)
			{
				head = p1;
				p1->Next = p2;
				p1->next = p2->address;
				p2 = p1;

			}
			else
			{
				p3->Next = p1;
				p3->next = p1->address;
				p1->Next = p2;
				p1->next = p2->address;
				p2 = p1;
			}
			j++;
		}
		p3 = p;
		p = p->Next;
		p2 = p;

	}
	return head;
}

void print(Node *head)//输出链表
{
	Node *p;
	p = head;
	while (p->Next)
	{
		printf("%05d %d %05d\n", p->address, p->date, p->next);
		p = p->Next;
	}
	printf("%05d %d %d\n", p->address, p->date, p->next);
}

int main()
{
	int first;
	int n, k;
	int i, t1, t2, t3;

	scanf("%d%d%d", &first, &n, &k);
	//create
	for (i = 0; i<n; i++)
	{
		scanf("%d%d%d", &t1, &t2, &t3);
		node[t1].address = t1;
		node[t1].date = t2;
		node[t1].next = t3;
	}
	Node*p = create(first);

	//reverse
	if (k == 1 || k == 0)
		print(p);
	else
	{
		num = num / k;
		p = reverse(p, k, num);
		print(p);
	}

	return 0;
}