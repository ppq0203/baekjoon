#include <stdio.h>
#include <stdlib.h>

int supervisor();

int main(){
	supervisor();
	return 0;
}

void total_add(char[14], int);

int supervisor() {
	int n, a, b, c, *room, count;
	char total[14];

	for(int i = 0; i < 13; i++)
	{
		total[i] = '0';
	}
	total[13] = '\0';

	room = (int*)malloc(sizeof(int)*1000000);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		*(room+i) = a;
	}
	scanf("%d %d", &b, &c);

	for(int i = 0; i < n; i++)
	{
		*(room+i) -= b;
		count = 1;
		if(*(room+i)>0)
		{
			*(room+i) += c-1;
			count += *(room+i)/c;	
		}
		total_add(total, count);
	}
	int start = 0;
	while(total[start] == '0')
	{
		start++;
	}
	printf("%s\n", total+start);
	return 0;
}

void total_add(char total[14], int count)
{
	for(int i = 10, j = 0, num =0; count > 0 || num == 1; i*=10, j++)
	{
		num += count%10;
		total[12-j] += num;
		if(total[12-j] > '9')
		{
			total[12-j] -= 10;
			num = 1;
		}
		else
		{
			num = 0;
		}
		count /= 10;
	}
}