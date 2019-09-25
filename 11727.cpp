#include <stdio.h>

int tiling(int);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	printf("%d\n", tiling(n)%10007);
	return 0;
}

int tiling(int n)
{
	int tile[1001];
	tile[0] = 1;
	tile[1] = 1;
	for(int i = 2; i <= n; i++)
		tile[i] = (tile[i-1] + 2*tile[i-2]) % 10007;
	return tile[n];
}