#include <stdio.h>
#include <stdlib.h>
#define FIBOMAX 40
#define LISTLENGTH 2

int** pointerlistmemory(int);
void fiboset(int**, int);

int main() {
	//setting
	int **fibonacci01;
	fibonacci01 = pointerlistmemory(FIBOMAX);
	fiboset(fibonacci01, FIBOMAX);
	// test
	int testcase, fibonum;
	scanf("%d", &testcase);
	while(testcase--) { // loop testcase time
		scanf("%d", &fibonum);	//input fibonacci number
		printf("%d %d\n", **(fibonacci01+fibonum), *(*(fibonacci01+fibonum)+1) );	// fibonacci01[fibonum][0], fibonacci01[fibonum][1]
	}	
}

int** pointerlistmemory(int n) {	// 0~n then 1+n int pointer list memory set
	return (int**)malloc((n+1)*sizeof(int*)); 
}
int* intlistmemory(int n) {	// n int list memory set
	return (int*)malloc(n*sizeof(int)); 
}

void fiboset(int** list, int n) {
	for(int i = 0; i <= n; i++)
	{
		*(list+i) = intlistmemory(2);
		if(i == 0) {
			*(*(list+i)+0) = 1;	// *(*(list+i)+0) == list[i][0]
			*(*(list+i)+1) = 0;	// *(*(list+i)+1) == list[i][1]
		} else if(i == 1) {
			*(*(list+i)+0) = 0;	// *(*(list+i)+0) == list[i][0]
			*(*(list+i)+1) = 1;	// *(*(list+i)+1) == list[i][1]
		} else {	// if i > 1
			*(*(list+i)+0) = *(*(list+i-1)+0) + *(*(list+i-2)+0);	// list[i][0] = list[i-1][0] + list[i-2][0]
			*(*(list+i)+1) = *(*(list+i-1)+1) + *(*(list+i-2)+1);	// list[i][0] = list[i-1][0] + list[i-2][0]
		}
	}
}
