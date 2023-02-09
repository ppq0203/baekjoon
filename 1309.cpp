#include <stdio.h>

#define L 0 //Left
#define R 1 //Right
#define E 2 //Empty
#define MAX 100000 // n <= 100000

int zoo(int);

int main(int argc, char const *argv[])
{
	int length;
	scanf("%d", &length);
	printf("%d", zoo(length));
	return 0;
}

int zoo(int n)
{
	int lion[3][MAX];
	lion[L][0] = 1;
	lion[R][0] = 1;
	lion[E][0] = 1;
	for(int i = 1; i < n; i++)
	{
		lion[L][i] = lion[R][i-1]+lion[E][i-1];
		lion[R][i] = lion[L][i-1]+lion[E][i-1];
		lion[E][i] = lion[L][i-1]+lion[R][i-1]+lion[E][i-1];
		lion[L][i] %= 9901;
		lion[R][i] %= 9901;
		lion[E][i] %= 9901;
	}
	return (lion[L][n-1]+lion[R][n-1]+lion[E][n-1])%9901;
}