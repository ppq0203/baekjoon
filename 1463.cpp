#include <stdio.h>
#include<stdlib.h>
#define MAX 1001
#define min(a,b) a>b?b:a

int making_1(int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n", making_1(n));
	return 0;
}

int making_1(int n)
{
	int *num = (int *)malloc(sizeof(int)*(n+1));
	for (int i = 2; i <= n; i++)
	{
		num[i] = num[i-1]+1;
		if(i%2==0)
			num[i] = min(num[i],num[i/2]+1);
		if(i%3==0)
			num[i] = min(num[i],num[i/3]+1);
	}
	return num[n];
}