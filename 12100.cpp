#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define MAX 20

int game2048(int);

int main(int argc, char const *argv[])
{
	int maxnum, n;
	scanf("%d", &n);
	maxnum = game2048(n);
	printf("%d\n", maxnum);
	return 0;
}

int map_setting(int* maps, int n);
int move_block(int*, int*, int, int, int);

int game2048(int n)
{
	int maxnum, num;
	int* maps, *newmaps;
	maps = (int*)malloc(sizeof(int)*(n*n+1)); // last list value is move count
	maxnum = map_setting(maps, n);
	std::stack<int*> mapstack;
	mapstack.push(maps);
	while(!mapstack.empty())
	{
		maps = mapstack.top();
		mapstack.pop();
		if(maps[n*n] < 5)
		{
			newmaps = (int*)malloc(sizeof(int)*(n*n+1));
			num = move_block(maps, newmaps, n, -1, 0); // move up
			maxnum = num>maxnum?num:maxnum;
			mapstack.push(newmaps);

			newmaps = (int*)malloc(sizeof(int)*(n*n+1));
			num = move_block(maps, newmaps, n, 1, 0); // move down
			maxnum = num>maxnum?num:maxnum;
			mapstack.push(newmaps);

			newmaps = (int*)malloc(sizeof(int)*(n*n+1));
			num = move_block(maps, newmaps, n, 0, -1); // move left
			maxnum = num>maxnum?num:maxnum;
			mapstack.push(newmaps);

			newmaps = (int*)malloc(sizeof(int)*(n*n+1));
			num = move_block(maps, newmaps, n, 0, 1); // move right
			maxnum = num>maxnum?num:maxnum;
			mapstack.push(newmaps);
		}
		free(maps);
	}
	
	return maxnum;
}

int map_setting(int* maps, int n)
{
	int maxnum = 0, num;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d", &num);
			maps[i*n+j] = num;
			if(num > maxnum)
				maxnum = num;
		}
	}
	maps[n*n] = 0;
	return maxnum;
}

int move_block(int* maps, int* newmaps, int n, int ud, int lr) // ud -1 : up, ud 1 : down, lr -1 : left, lr 1 : right
{
	int maxnum = 0, num, beforenum;
	for(int i = 0, k; i < n; i++)
	{
		num = 0;
		beforenum = 0;
		k = 0;
		for (int j = 0; j < n; ++j)
		{
			num = maps[n* ((-j+((n-1)*ud+(n-1))/2)*ud + lr*lr*i) + ((-j+((n-1)*lr+(n-1))/2)*lr + ud*ud*i)]; // up : n*j+i down : n*(n-1-j)+i left : n*i+j right: n*i+(n-1-j)
			if(num!=0)
			{
				if(beforenum == num)
				{
					newmaps[n*((-(k-1)+((n-1)*ud+(n-1))/2)*ud + lr*lr*i) + (-(k-1)+((n-1)*lr+(n-1))/2)*lr + ud*ud*i] *= 2; // up : n*(k-1)+i down : n*(n-k)+i left : n*i+(k-1) right: n*i+(n-k)

					maxnum = num*2>maxnum?num*2:maxnum;
					beforenum = 0;
				}
				else // beforenum != num
				{
					newmaps[n*((-k+((n-1)*ud+(n-1))/2)*ud + lr*lr*i)+(-k+((n-1)*lr+(n-1))/2)*lr + ud*ud*i] = num; // up : n*k+i down : n*(n-1-k)+i left : n*i+k right: n*i+(n-1-k)
					beforenum = num;
					k++;
				}
			}
		}
		while(k < n)
		{
			newmaps[n*((-k+((n-1)*ud+(n-1))/2)*ud + lr*lr*i)+(-k+((n-1)*lr+(n-1))/2)*lr + ud*ud*i] = 0;
			k++;
		}
	}
	newmaps[n*n] = maps[n*n]+1; // move count
	return maxnum;
}