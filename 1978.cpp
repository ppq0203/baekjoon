#include <stdio.h>

int main(){
	int casenum;
	int num;
	int synthetic;
	int count = 0;
	scanf("%d", &casenum);
	while (casenum--){
		scanf("%d", &num);
		if (num == 2)
			count++;
		else if (num != 1 && num % 2 != 0)
		{
			synthetic = 0;
			for (int j = 3; j * j <= num; j += 2){
				if (num % j == 0){
					synthetic = 1;
					break;
				}
			}
			if (synthetic == 0)
				count++;
		}
	}
	printf("%d\n", count);
	return 0;
}