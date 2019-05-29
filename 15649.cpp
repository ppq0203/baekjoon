#include <stdio.h>
#define MAX 9

int printlist(int,int,int[MAX],int);

int main()
{
	int n, m;
	int position = 1;
	scanf("%d %d", &n, &m);
	int list[MAX];
	printlist(n,m,list, position);

	return 0;
}


int printlist(int n, int m, int list[MAX], int position)
{
	int include;
	if(position > m)
	{
		for(int i = 1; i <= m; i++)
		{
			printf("%d ", list[i]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			include = 0;
			for(int j = 1; j < position; j++)
				if(list[j] == i)
					include = 1;
			if (include == 0)
			{
				list[position] = i;
				printlist(n, m, list, position+1);
			}
		}
		return 0;
	}
}
