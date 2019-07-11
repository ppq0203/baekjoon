#include <stdio.h>
#define MAX 500001
int queue[MAX];
int first = 0;
int last = 0;

void push(int);
int pop();
void card2(int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	card2(n);
	return 0;
}

void card2(int n)
{
	int value;
	for (int i = 1; i <= n; ++i)
		push(i);
	for (int i = 0; i < n; ++i)
	{
		value = pop();
		push(pop());
	}
	printf("%d\n", value);
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