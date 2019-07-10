#include <stdio.h>
#define MAX 5001
int queue[MAX];
int first = 0;
int last = 0;

void push(int);
int pop();

void josephus(int, int);

int main(int argc, char const *argv[])
{
	int n, k;
	scanf("%d %d", &n, &k);
	josephus(n, k);
	return 0;
}

void josephus(int n, int k)
{
	for (int i = 1; i <= n; ++i)
		push(i);
	for (int i = 0; i < n; ++i)
	{
		if(i == 0)
			printf("<");
		for (int j = 0; j < k-1; j++)
			push(pop());
		printf("%d", pop());
		if(i != n-1)
			printf(", ");
		else
			printf(">\n");
	}

}

void push(int num)
{
	queue[last++] = num;
	last %= MAX;
}

int pop()
{
	int value = queue[first++];
	first %= MAX;
	return value;
}