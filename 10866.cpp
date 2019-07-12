#include <stdio.h>
#include <string.h>
#define MAX 10001
#define PUSH_F "push_front"
#define PUSH_B "push_back"
#define POP_F "pop_front"
#define POP_B "pop_back"
#define SIZE "size"
#define EMPTY "empty"
#define FRONT "front"
#define BACK "back"

int queue[MAX];
int first = 0;
int last = 0;

void deque(char*);

int main(int argc, char const *argv[])
{
	int t_c;
	char order[12];
	scanf("%d", &t_c);
	while(t_c--)
	{
		scanf("%s", order);
		deque(order);
	}
	return 0;
}

void push_front(int);
void push_back(int);
int pop_front();
int pop_back();
int size();
int empty();
int front();
int back();

void deque(char* order)
{
	int n;
	if (!strcmp(order, PUSH_F))
	{
		scanf("%d", &n);
		push_front(n);
	}
	else if (!strcmp(order, PUSH_B))
	{
		scanf("%d", &n);
		push_back(n);
	}
	else if (!strcmp(order, POP_F)) 
		printf("%d\n", pop_front());
	else if (!strcmp(order, POP_B)) 
		printf("%d\n", pop_back());
	else if (!strcmp(order, SIZE)) 
		printf("%d\n", size());
	else if (!strcmp(order, EMPTY)) 
		printf("%d\n", empty());
	else if (!strcmp(order, FRONT)) 
		printf("%d\n", front());
	else if (!strcmp(order, BACK)) 
		printf("%d\n", back());
}

void push_front(int num)
{
	first = (MAX+first-1)%MAX;
	queue[first] = num;
}

void push_back(int num)
{
	queue[last++] = num;
	last = last%MAX;
}

int size()
{
	return (MAX+last-first)%MAX;
}

int empty()
{
	if (first == last)
		return 1;
	else // first != last
		return 0;
}

int pop_front()
{
	if (empty())
		return -1;
	int value = queue[first++];
	first = first%MAX;
	return value;
}

int pop_back()
{
	if (empty())
		return -1;
	last = (last-1+MAX)%MAX;
	int value = queue[last];
	return value;
}

int front()
{
	if (empty())
		return -1;
	return queue[first];
}

int back()
{
	if (empty())
		return -1;
	return queue[(last-1+MAX)%MAX];
}