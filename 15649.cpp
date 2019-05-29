#include <stdio.h>
#define MAX 9 //n ,m <= 8

int printlist(int,int,int[MAX],int);

int main()
{
	int n, m;
	int position = 1; // start list position = 1
	scanf("%d %d", &n, &m); // input n,m 
	int list[MAX]; // 
	printlist(n,m,list, position);

	return 0;
}


int printlist(int n, int m, int list[MAX], int position) // make & print number
{
	int include;
	if(position > m) // if makelist finish print list
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
		for(int i = 1; i <= n; i++) // loop 1~n
		{
			include = 0;
			for(int j = 1; j < position; j++)
				if(list[j] == i) // compare previous number
					include = 1;
			if (include == 0) // If the numbers are not there before
			{
				list[position] = i; // put list number
				printlist(n, m, list, position+1); // find next number
			}
		}
		return 0;
	}
}
