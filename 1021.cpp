#include <stdio.h>
#define MAX 51
#define MIN(a,b) ((a>b)?b:a)

void setting(int, int*, int*, int*);
void push_front(int, int*, int*, int*);
void push_back(int, int*, int*, int*);
int pop_front(int*, int*, int*);
int pop_back(int*, int*, int*);
int empty(int*, int*, int*);
int front_v(int*, int*, int*);
int leftque_algorithm(int, int*, int*, int*);
int rightque_algorithm(int, int*, int*, int*);

int main(int argc, char const *argv[])
{
	int leftque[MAX];
	int left_f = 0;
	int left_b = 0;
	int rightque[MAX];
	int right_f = 0;
	int right_b = 0;

	int elementnum;
	scanf("%d", &elementnum);
	setting(elementnum, leftque, &left_f, &left_b);
	setting(elementnum, rightque, &right_f, &right_b);

	int popnum;
	scanf("%d", &popnum);
	int findnum;
	int count = 0;
	int a, b;
	while (popnum--)
	{
		scanf("%d", &findnum);
		a = leftque_algorithm(findnum, leftque, &left_f, &left_b);
		b = rightque_algorithm(findnum, rightque, &right_f, &right_b);
		count += MIN(a, b);
	}
	printf("%d\n", count);
	return 0;
}

int leftque_algorithm(int findnum, int *queue, int *front, int *back)
{
	int count = 0;
	while (front_v(queue, front, back) != findnum)
	{
		push_front(pop_back(queue, front, back), queue, front, back);
		count++;
	}
	pop_front(queue, front, back);
	return count;
}

int rightque_algorithm(int findnum, int *queue, int *front, int *back)
{
	int count = 0;
	while (front_v(queue, front, back) != findnum)
	{
		push_back(pop_front(queue, front, back), queue, front, back);
		count++;
	}
	pop_front(queue, front, back);
	return count;
}




void setting(int num, int *queue, int *front, int *back)
{
	for (int i = 1; i <= num; i++)
	{
		push_back(i, queue, front, back);
	}
}

void push_front(int num, int *queue, int *front, int *back)
{
	*front = (MAX+*front-1)%MAX;
	queue[*front] = num;
}

void push_back(int num, int *queue, int *front, int *back)
{
	queue[(*back)++] = num;
	*back = *back%MAX;
}

int empty(int *queue, int *front, int *back)
{
	if (*front == *back)
		return 1;
	else // *front != *back
		return 0;
}

int pop_front(int *queue, int *front, int *back)
{
	if (empty(queue, front, back))
		return -1;
	int value = queue[(*front)++];
	*front = *front%MAX;
	return value;
}

int pop_back(int *queue, int *front, int *back)
{
	if (empty(queue, front, back))
		return -1;
	*back = (*back-1+MAX)%MAX;
	int value = queue[*back];
	return value;
}

int front_v(int *queue, int *front, int *back)
{
	if (empty(queue, front, back))
		return -1;
	return queue[*front];
}