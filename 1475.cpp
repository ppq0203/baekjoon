#include <stdio.h>
#define MAX 8

int findset(char[MAX]);

int main(int argc, char const *argv[])
{
	char roomnum[MAX]; // roomnum <= 1,000,000
	int set;
	scanf("%s", roomnum);
	set = findset(roomnum);
	printf("%d\n", set);
	return 0;
}

int findset(char roomnum[MAX])
{
	int use_num[10] = {0};
	int saveneedset;
	int needmaxset = 0;
	for (int i = 0; i < MAX; i++)
	{
		if(roomnum[i] == '\0') // find string's end then return value
			return needmaxset;
		if(roomnum[i] == '9') // 6&9 can swap
			roomnum[i] = '6';
		saveneedset = ++use_num[roomnum[i]-'0'];
		if(roomnum[i] == '6') // 6&9's need set
			saveneedset = saveneedset/2 + saveneedset%2;
		if(saveneedset > needmaxset) // max need set Update
			needmaxset = saveneedset;
	} 
}