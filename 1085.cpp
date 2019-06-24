#include <stdio.h>
#define min(a,b) a>b?b:a

int main(int argc, char const *argv[])
{
	int x, y, w, h;
	int min_value;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	min_value = min(x, w-x);
	min_value = min(min_value, y);
	min_value = min(min_value, h-y);
	printf("%d\n", min_value);
	return 0;
}