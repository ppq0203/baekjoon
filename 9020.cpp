#include <stdio.h>
#include <math.h>
#define MAX 10000
#define TRUE 1
#define FALSE 0

void setting(int*, int);
void goldbach(int*, int);

int main(int argc, char const *argv[])
{
	int testcase, number;
	scanf("%d", &testcase);

	int decimal[MAX] = {0};
	setting(decimal, MAX);
	while (testcase--)
	{
		scanf("%d", &number);
		goldbach(decimal, number);
	}
	return 0;
}


void goldbach(int *decimal, int num)
{
	for (int s_dec = num/2, b_dec = num/2; s_dec > 1; s_dec--, b_dec++)
	{
		if(decimal[s_dec]&&decimal[b_dec])
		{
			printf("%d %d\n", s_dec, b_dec);
			return;
		}
	}
}

void setting(int *decimal, int max)
{
	int is_decimal;
	for(int i = 2; i < max; ++i)
	{
		if (i == 2)
			decimal[i] = TRUE;
		if (i % 2 == 1)
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
				decimal[i] = TRUE;
		}
	}
	return ;
}