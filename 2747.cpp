#include <stdio.h>

int fibonacci(int);

int main(int argc, char const *argv[])
{
	int n, fibo;
	scanf("%d", &n);
	fibo = fibonacci(n);
	printf("%d\n", fibo);
	return 0;
}

int fibonacci(int n)
{
	int even = 0, odd = 1;
	for(int i = 1; i <= n; ++i)
	{
		if(i%2 == 0) // even
			even += odd;
		else // odd
			odd += even;
	}
	if(n%2 == 0) // even
		return even;
	else // odd
		return odd;
}
