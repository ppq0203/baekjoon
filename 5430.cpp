#include <stdio.h>
#define MAX 100001

void ac_algorithm();

int main(int argc, char const *argv[])
{
	int t; //testcase t<=100
	scanf("%d", &t);
	while(t--){
		ac_algorithm();
	}
	return 0;
}

int setting(int*);

void ac_algorithm()
{
	char p[MAX]; //AC language function
	int list[MAX];
	int list_front = 0;
	int list_back;
	int reverse = 0; // basic value is 0
	scanf("%s", p);
	printf("%s\n", p);
	list_back = setting(list);

	// operation
	for(int i = 0; p[i] != '\0'; ++i)
	{
		if (p[i] == 'R')
			reverse++;
		else // p[i] == 'D'
		{
			if (reverse%2 == 0) // same basic
			{
				list_front++; // remove firstnum;
			}
			else // reverse basic
				list_back--; // remove firstnum;
		}
	}

	if(list_front > list_back)
	{
		printf("error\n");
		return;
	}

	// print
	if(reverse%2 == 0) // same basic
	{
		printf("[");
		for(int i = list_front; i < list_back; ++i)
		{
			if (i != list_back-1)
				printf("%d,", list[i]);
			else // end
				printf("%d]\n", list[i]);
		}
	}
	else // reverse basic
	{
		printf("[");
		for(int i = list_back-1; i >= list_front; --i)
		{
			if (i != list_front)
				printf("%d,", list[i]);
			else // end
				printf("%d]\n", list[i]);
		}
	}
}

// input
int setting(int *list)
{
	int num;
	scanf("%d", &num);
	getchar(); // getchar '\n'
	getchar(); // getchar '['
	for (int i = 0; i < num; ++i)
	{
		scanf("%d", list+i);
		getchar(); // getchar ',' or ']'
	}
	return num;
}