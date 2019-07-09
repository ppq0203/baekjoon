#include <stdio.h>

char balance(char);

int main(int argc, char const *argv[])
{
	char c;
	while((c = getchar()) != '.')
	{
		c = balance(c);
		while(c != '.')
			c = getchar();
		c = getchar(); // c = \n
	}
	return 0;
}

char balance(char c)
{
	char stack[100] = {0};
	int posi = 0;
	while(c != '.')
	{
		switch (c)
		{
		case '[' :
			stack[posi++] = '[';
			break;
		case ']' :
			if (stack[--posi] != '[') // not balance 
			{
				printf("no\n");
				return c;
			}
			stack[posi] = 0;
			break;
		case '(' :
			stack[posi++] = '(';
			break;
		case ')' :
			if (stack[--posi] != '(') // not balance 
			{
				printf("no\n");
				return c;
			}
			stack[posi] = 0;
			break;
		}
		c = getchar();
	}
	if (posi != 0) // remain stack
		printf("no\n");
	else
		printf("yes\n");
	return c; // return '.'
}