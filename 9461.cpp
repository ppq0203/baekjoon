#include <stdio.h>
#define MAX 101

void spiral_set(long int *);

int main(int argc, char const *argv[])
{
	long int side[MAX];
	spiral_set(side);
	int testcase, num;
	scanf("%d", &testcase);
	while (testcase--)
	{
		scanf("%d", &num);
		printf("%ld\n", side[num]);
	}
	return 0;
}

void spiral_set(long int *side)
{
	side[1] = 1;
	side[2] = 1;
	side[3] = 1;
	side[4] = 2;
	side[5] = 2;
	for(int i = 6; i <= 100; ++i)
		side[i] = side[i-1]+side[i-5];
}
