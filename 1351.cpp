#include <stdio.h>
#define LIST_NUM 100000

long long int infinity_array(long long int*, long long int, long long int, long long int);
void setlist(long long int *, long long int, long long int);

int main(int argc, char const *argv[])
{
	long long int n, p, q;
	long long int list[LIST_NUM];
	scanf("%lld %lld %lld", &n, &p, &q);
	setlist(list,p,q);
	printf("%lld\n", infinity_array(list,n,p,q));
	return 0;
}

void setlist(long long int *list, long long int p, long long int q)
{
	list[0] = 1;
	for(int i = 1; i < LIST_NUM; i++)
	{
		list[i] = list[i/p] + list[i/q];
	}
	
}

long long int infinity_array(long long int *list, long long int n, long long int p, long long int q)
{
	if (n < LIST_NUM)
		return list[n];
	long long int value = infinity_array(list,n/p,p,q);
	value += infinity_array(list,n/q,p,q);
	return value;
}
