#include <stdio.h>
#define FIBOMAX 40
#define LISTLENGTH 2

void fiboset(int[FIBOMAX+1][LISTLENGTH]);

int main() {
	//setting
	int fibonacci01[FIBOMAX][LISTLENGTH];
	fiboset(fibonacci01);
	// test
	int testcase, fibonum;
	scanf("%d", &testcase);
	while(testcase--) { // loop testcase time
		scanf("%d", &fibonum);	//input fibonacci number
		printf("%d %d\n", fibonacci01[fibonum][0], fibonacci01[fibonum][1]);
	}	
}

void fiboset(int list[FIBOMAX+1][LISTLENGTH]) {
	for(int i = 0; i <= FIBOMAX; i++)
	{
		if(i == 0) {
			list[i][0] = 1;
			list[i][1] = 0;
		} else if(i == 1) {
			list[i][0] = 0;
			list[i][1] = 1;
		} else {	// if i > 1
			list[i][0] = list[i-1][0] + list[i-2][0];
			list[i][1] = list[i-1][1] + list[i-2][1];
		}
	}
}
