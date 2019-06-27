#include <stdio.h>

int roomcount(int);

int main(int argc, char const *argv[])
{
	int roomnum;
	int count;
	scanf("%d", &roomnum);
	count = roomcount(roomnum);
	printf("%d\n", count);
	return 0;
}

int roomcount(int roomnum)
{
	int count = 1;
	roomnum--;
	for (int i = 1; roomnum>0; i++)
	{
		roomnum-= i*6;
		count++;
	}
	return count;
}