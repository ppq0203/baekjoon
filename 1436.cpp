#include <stdio.h>
#include <string.h>
#define MAX 8

int main(int argc, char const *argv[])
{
	int n;
	char movienum[MAX];
	char key[4] = "666";
	scanf("%d", &n); // input
	int findnum = 0; // num contain 666 +count
	for (int num = 666; findnum < n; num++) // first title is 666
	{
		sprintf(movienum, "%d", num); // int to string
		if (strstr(movienum, key) != NULL) // movienum contain key
			findnum++;
	}
	printf("%s", movienum);
	return 0;
}
