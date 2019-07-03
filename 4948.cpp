#include <stdio.h>
#include <math.h>
#define MAX 246913
#define TRUE 1
#define FALSE 0

void bertrand();

int main(int argc, char const *argv[])
{
	bertrand();
	return 0;
}

void setting(int *, int);

void bertrand()
{
	int n;
	int decimal[MAX] = {0};
	setting(decimal, MAX);
	while(TRUE)
	{
		scanf("%d", &n);
		if (n == 0)
			return;
		printf("%d\n", decimal[2*n]-decimal[n]);
	}
}

void setting(int *decimal, int max)
{
	int is_decimal;
	for(int i = 1; i < max; ++i)
	{
		decimal[i] = decimal[i-1];
		if (i == 2)
			decimal[i] = 1;
		if (i > 2 && i % 2 == 1)
		{
			is_decimal = TRUE;
			for (int j = 3; j <= (int)sqrt(i); j+=2)
			{
				if(i % j == 0)
				{
					is_decimal = FALSE;
					break;
				}
			}
			if (is_decimal == TRUE)
				decimal[i]++;
		}
	}
	return ;
}