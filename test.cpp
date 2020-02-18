#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>


int main(int argc, char const *argv[])
{
//	std::stack<int*> S1, S2, *saveS;
//	int* a;
//	int b[3] = {1,2,3};
//	a = b;
//	S1.push(a);
//	int c[3] = {4,5,6};
//	a = c;
//	S1.push(a);
//	a = (int*)malloc(3*sizeof(int));
//	a[0] = 7;
//	a[1] = 8;
//	a[2] = 9;
//	S1.push(a);
//	saveS = &S1;
//	saveS->pop();
//	//printf("%d\n", saveS->top()[1]);
//	//printf("%d\n", S1.top()[1]);
//	printf("%d", !(2%2));
	std::queue<int*> que;
	int a;
	a= 10;
	que.push(&a);
	a= 20;
	que.push(&a);
	a= 30;
	que.push(&a);
	a= 40;
	que.push(&a);
	printf("%d %d\n", *que.front(), *que.back());
	que.pop();
	printf("%d %d\n", *que.front(), *que.back());
	return 0;
}
