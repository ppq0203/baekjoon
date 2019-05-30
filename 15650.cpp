#include <stdio.h>
#define MAX 9 //n ,m <= 8

int makelist(int,int,int[MAX],int);

int main()
{
	int n, m;
	int position = 1; // start list position = 1
	scanf("%d %d", &n, &m); // input n,m 
	int list[MAX] = {0}; // 
	makelist(n,m,list, position);

	return 0;
}

void printlist(int[MAX],int);

int makelist(int n, int m, int list[MAX], int position) // make & print number
{
	int include;
	if(position > m) // if makelist finish print list
	{
		printlist(list, m);
		return 0;
	}
	else
	{
		for(int i = list[position-1]+1; i <= n; i++) // loop previous number ~ n , if position = 1 (first loop),i = 1~n because list[0] = 0
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