#include <stdio.h>

int min_oper(int, int);

int main(int argc, char const *argv[])
{
	int testcase;
	int x, y, operation;
	scanf("%d", &testcase);
	while(testcase--)
	{
		scanf("%d %d", &x, &y);
		operation = min_oper(x, y);
		printf("%d\n", operation);
	}
	return 0;
}

int min_oper(int x, int y)
{
	int distance = y-x;
	int count = 0;
	int max_move = 1;
	while (distance > max_move*2)
	{
		distance -= max_move*2;
		count += 2;
		max_move++;
	}
	if (distance > max_move)
		count++;
	if (distance > 0)
		count++;
	return count;
}