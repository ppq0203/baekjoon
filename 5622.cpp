#include <stdio.h>

int main(int argc, char const *argv[])
{
	char phone[16];
	scanf("%s", phone);
	int count = 0;
	for (int i = 0; phone[i] != '\0'; ++i)
	{
		count+=3;
		if(phone[i] - 'A' < 15)
			count += (phone[i]-'A')/3;
		else if(phone[i] - 'A' < 19)
			count += 5;
		else if(phone[i] - 'A' < 22)
			count += 6;
		else
			count += 7;
	}
	printf("%d\n", count);
	return 0;
}