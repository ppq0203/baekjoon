#include <stdio.h>
#include <math.h>
#define MAX 100000
#define DECMAX 11000
#define TRUE 1
#define FALSE 0

void setting(int *, int);
void prime_factori(int *, int);

int main(int argc, char const *argv[])
{
	int dec[DECMAX]; // deciumal list {2,3,5,7,11,...}
	setting(dec, MAX);
	int testcase, number;
	scanf("%d", &testcase);
	while(testcase--) // loop testcase's number
	{
		scanf("%d", &number);
		prime_factori(dec, number);
	}
	return 0;
}


void setting(int *decimal, int max) // make decimal list
{
	int is_decimal;
	for(int i = 2, k = 0; i <= max; ++i)
	{
		if (i == 2)
			decimal[k++] = i;

		if (i % 2 == 1)
		{
			is_decimal = TRUE;
			for (int j = 0; j < k; ++j)
			{
				if(i % decimal[j] == 0)
				{
					is_decimal = FALSE;
					break;
				}
			}
			if (is_decimal == TRUE)
				decimal[k++] = i;
		}
	}
	return ;
}


void prime_factori(int *decimal, int number)
{
	for(int i = 0, count; number > 1; ++i)
	{
		count = 0;
		while(number % decimal[i] == 0)
		{
			number /= decimal[i];
			count++;
		}
		if (count > 0)
			printf("%d %d\n", decimal[i], count);
	}
}