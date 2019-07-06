#include <stdio.h>
int stack[100000];
int posi = 0;

int push(int);
int pop();
int size();

int main(int argc, char const *argv[])
{
	int c;
	int prev = 0;
	int count = 0;
	while((c = getchar()) == '(' || c == ')')
	{
		if (c == '(')
			push('(');
		else // c = ')'
		{
			pop();
			if (prev == '(')
				count += size();
			else //preve = ')'
				count++;
		}
		prev = c;
	}
	printf("%d\n", count);
	return 0;
}



int push(int value)
{
	stack[posi++] = value;
	return value;
}

int pop()
{
	int value = stack[--posi];
	stack[posi] = 0;
	return value;
}

int size()
{
	return posi;
}