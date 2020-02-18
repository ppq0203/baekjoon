#include <stdio.h>

int main(int argc, char const *argv[])
{
	char str[101];
	int count = 0;
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == '-')
			count--;
		if (str[i] == '=')
		{
			if (i > 1 && str[i-1] == 'z' && str[i-2] == 'd')
				count--;
			count--;
		}
		if (i > 0 && str[i] == 'j')
		{
			if (str[i-1] == 'l' || str[i-1] == 'n')
				count--;
		}
		count++;
	}
	printf("%d\n", count);

	return 0;
}