#include <stdio.h>
#define max(a,b) a>b?a:b

int goup_stairs(int);

int main(int argc, char const *argv[])
{
	int stair_num;
	scanf("%d", &stair_num);
	printf("%d", goup_stairs(stair_num));
	return 0;
}

int goup_stairs(int stair_n)
{
	int num;
	int stairs[3][300] = {0};

	for(int i = 0; i < stair_n; i++)
	{
		scanf("%d", &num);
		stairs[0][i] = num;
		if(i == 0)
		{
			stairs[1][i] = num;
			stairs[2][i] = num;
		}
		else if(i == 1)
		{
			stairs[1][i] = num;
			stairs[2][i] = num+stairs[1][i-1];
		}
		else
		{
			stairs[1][i] = max(num+stairs[2][i-2], num+stairs[1][i-2]);
			stairs[2][i] = num+stairs[1][i-1];
		}
	}
	return max(stairs[1][stair_n-1], stairs[2][stair_n-1]);
}