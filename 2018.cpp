#include <stdio.h>
#include <stdlib.h>
#define MAX 4001

void calc(int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	calc(n);
	return 0;
}

int compare(const void *a, const void *b)    // ascending order function
{
    int num1 = *(int *)a;    // void pointer change int pointer
    int num2 = *(int *)b;    // void pointer change int pointer

    if (num1 < num2)    // a < b
        return -1;       
    
    if (num1 > num2)    // a > b
        return 1;       
    
    return 0;    // a = b
}

int averfind(int sum, int n)
{
	int aver = sum/n;
	if (sum > 0 && sum%n >= (n+1)/2)
		aver++;
	if (sum < 0 && sum%n <= -(n+1)/2)
		aver--;
	return aver;
}

int modefind(int minus[MAX], int plus[MAX], int most)
{
	int mode = -MAX;
	for (int i = MAX-1; i > 0; --i)
	{
		if(minus[i] == most)
		{
			if (mode != -MAX)
				return -i;
			mode = -i;
		}
	}
	for (int i = 0; i < MAX; ++i)
	{
		if(plus[i] == most)
		{
			if (mode != -MAX)
				return i;
			mode = i;
		}
	}
	return mode;
}

void calc(int n)
{
	int number;
	int list[n];
	int plus[MAX] = {0};
	int minus[MAX] = {0};
	int sum = 0;
	int most = 0;
	int aver, mid, mode, range;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number);
		sum += number;
		list[i] = number;
		if (number<0)
		{
			number *= -1;
			if(++minus[number] > most)
				most = minus[number];
		}
		else //number>=0
		{
			if(++plus[number] > most)
				most = plus[number];
		}
	}
	qsort(list, n, sizeof(int), compare);
	aver = averfind(sum, n);
	mid = list[n/2];
	mode = modefind(minus, plus, most);
	range = list[n-1]-list[0];\
	printf("%d\n", aver);
	printf("%d\n", mid);
	printf("%d\n", mode);
	printf("%d\n", range);
}
