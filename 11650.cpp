#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 2

int compare_arrays(const void* arr1, const void* arr2)
{
	const int* one = (const int*) arr1;
	const int* two = (const int*) arr2;
	for(int i = 0; i < ARRAY_SIZE; i++)
	{
		if(one[i] < two[i])
			return -1;
		if(one[i] > two[i])
			return 1;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int n, x, y;
	scanf("%d", &n);
	int position[n][ARRAY_SIZE];
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", position[i], position[i]+1);
	}
	qsort(position[0], n, sizeof(int[ARRAY_SIZE]), compare_arrays);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", position[i][0], position[i][1]);
	return 0;
}