#include <stdio.h>

int main() {
	int list[5][5];
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			list[i][j] = i*5+j;
	printf("%d\n", list[1][2]);
	printf("%d\n", *(*(list+2)+1));
	printf("%d\n", (*list)[3]);
	
	
	return 0;
}
