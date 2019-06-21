#include <stdio.h>
#include <string.h>
#include <math.h>

void hanoialgorithm(int, int, int, int);

int main(int argc, char const *argv[])
{
	int platenum;
	scanf("%d", &platenum);
	printf("%.0f\n", pow(2, platenum)-1);
	hanoialgorithm(platenum, 1, 2, 3);
	return 0;
}

void hanoialgorithm(int platenum, int a, int b, int c)
{
	if (platenum==1) // leave only one then it move to c
		printf("%d %d\n", a, c);
	else // platenum > 1;
	{
		hanoialgorithm(platenum-1, a, c, b); 	// leave a single plate to go all the way a to b
		printf("%d %d\n", a, c);				// move biggist plates a to b
		hanoialgorithm(platenum-1, b, a, c); 	// move all the plates b to c
	}
}