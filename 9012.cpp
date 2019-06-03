#include <stdio.h>
#include <string.h>
#define MAX 51

int checkstr(char [MAX]);

int main(int argc, char const *argv[])
{
	char str[MAX];
	int testdata;
	scanf("%d", &testdata);
	while(testdata--) 		// loop testdata's number
	{
		scanf("%s", str); 	// input string
		if(checkstr(str)) 	// return 1
			printf("YES\n");
		else 				// return 0
			printf("NO\n");
	}

	return 0;
}

int checkstr(char str[MAX])
{	
	char stack[MAX] = {0}; 	// reset stack
	int position = 0;		// reset stack position
	char c; 		
	for(int i = 0; str[i] != '\0'; ++i) // loop string's end
	{
		c = str[i];
		if (c == '(')
		{
			stack[position++] = '('; 	// push stack
		}
		else // c == ')'
		{
			if (position == 0) // can't pop
				return 0;
			else
				stack[--position] = 0; 	// pop stack
		}
	}
	if (position) 	// remain in price
		return 0;
	else			// clear
		return 1;
}