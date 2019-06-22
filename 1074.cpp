#include <stdio.h>
#include <math.h>

int visitalgorithm(int, int, int);

int main(int argc, char const *argv[])
{
	int n, r, c;
	int visitcount;
	scanf("%d %d %d", &n, &r, &c);
	visitcount = visitalgorithm(n, r, c);
	printf("%d\n", visitcount);
	return 0;
}

int visitalgorithm(int n, int row, int column)
{
	if (n < 1)
		return 0;
	int arraylenght = pow(2, n);
	int count = 0;
	if (row >= arraylenght/2) // row and column's position is 2 or 4 quadrant
	{
		count += pow(arraylenght/2,2)*2;
		row -= arraylenght/2;
	}
	if (column >= arraylenght/2) // row and column's position is 3 or 4 quadrant
	{
		count += pow(arraylenght/2,2);
		column -= arraylenght/2;
	}
	count += visitalgorithm(n-1, row, column); // found inside quadrant 
	return count;
}