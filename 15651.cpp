#include <stdio.h>
#define MAX 9 //n ,m <= 8

int makelist(int,int,int[MAX],int);

int main()
{
	int n, m;
	int position = 1; // start list position = 1
	scanf("%d %d", &n, &m); // input n,m 
	int list[MAX]; // 
	makelist(n,m,list, position);

	return 0;
}

void printlist(int[MAX],int);

int makelist(int n, int m, int list[MAX], int position) // make & print number
{
	if(position > m) // if makelist finish print list
	{
		printlist(list, m);
		return 0;
	}
	else
	{
		for(int i = 1; i <= n; i++) // loop 1~n
		{
			list[position] = i; // put list number
			makelist(n, m, list, position+1); // find next number
		}
		return 0;
	}
}

void printlist(int list[MAX], int m)
{
	for(int i = 1; i <= m; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}