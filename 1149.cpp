#include <stdio.h>

#define R 0
#define G 1
#define B 2
#define MAX 1000
#define min(a,b) a>b?b:a

int rgb_street(int);

int main(int argc, char const *argv[])
{
	int street_langth;
	int value;
	scanf("%d", &street_langth);
	value = rgb_street(street_langth);
	printf("%d\n", value);
	return 0;
}

int rgb_street(int n)
{
	int price[3][MAX] ={0};
	int red, blue, green;
	int value;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &red, &green, &blue);
		if(i == 0)
		{
			price[R][i] = red;
			price[G][i] = green;
			price[B][i] = blue;
		}
		else
		{
			price[R][i] = red + (min(price[G][i-1], price[B][i-1]));
			price[G][i] = green + (min(price[R][i-1], price[B][i-1]));
			price[B][i] = blue + (min(price[R][i-1], price[G][i-1]));
		}
	}
	value = (min(price[R][n-1],(min(price[G][n-1], price[B][n-1]))));
	return value;
}
