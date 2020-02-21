#include <stdio.h>
#define MAX 15


int main() {
    int day, t[15] = {0}, p[15] = {0}, dfs[MAX+1] = {0}, num, pay;
    scanf("%d", &day);
    for(int i = 0; i < day; ++i)
    {
        scanf("%d %d", t+i, p+i);
    }
    for(int i = 0; i < day; ++i)
    {
        pay = 0;
        if(i+1 >= t[day-1-i])
        {
            pay = p[day-1-i] + dfs[day-1-i+t[day-1-i]];
        }
        dfs[day-1-i] = dfs[day-i]>pay?dfs[day-i]:pay;
    }

    printf("%d\n", dfs[0]);

    return 0;
}