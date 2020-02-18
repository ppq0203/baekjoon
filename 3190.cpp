#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define MAX 100
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1

void snake_game();

int main(int argc, char const *argv[])
{
	snake_game();
	return 0;
}

void apples_input(int[MAX][MAX], int);
int move(int[MAX][MAX], int[MAX][MAX], int, int, std::queue<int*>*);

void snake_game()
{
	int n, k, l, count;
	scanf("%d %d", &n, &k);
	int snake[MAX][MAX];
	int apples[MAX][MAX];
	std::queue<int*> que;
	memset(snake, 0, sizeof(int)*10000);
	memset(apples, 0, sizeof(int)*10000);

	//base snake setting
	int* snake_dir;
	snake_dir = (int*)malloc(sizeof(int)*2); // 0: y-Coordinates, 1: x-Coordinates 2: Direction
	snake_dir[0] = 0;
	snake_dir[1] = 0;
	snake[0][0] = 1;
	que.push(snake_dir);

	apples_input(apples, k);

	scanf("%d", &l);
	count = move(snake, apples, n, l, &que);

	printf("%d\n", count);
}

void apples_input(int apples[MAX][MAX], int k){
	int x, y;
	while(k--)
	{
		scanf("%d %d", &y, &x);
		apples[--y][--x] = 1;
	}
}

int move(int snake[MAX][MAX], int apples[MAX][MAX], int n, int l, std::queue<int*>* que){
	int* snake_dir, x_po, y_po, dir, time, count;
	char c;
	count = 0;
	dir = RIGHT;
	scanf("%d %c", &time, &c);
	l--;

	while(1)
	{
		count++;
		snake_dir = que->back();
		y_po = snake_dir[0];
		x_po = snake_dir[1];
		switch(dir)
		{
			case UP:
				y_po--;
				break;
			case DOWN:
				y_po++;
				break;
			case LEFT:
				x_po--;
				break;
			case RIGHT:
				x_po++;
				break;
		}
		if(y_po < 0 || y_po >= n || x_po < 0 || x_po >= n) // map breakaway
			return count;
		if(snake[y_po][x_po] == 1) // meet snake's body
			return count;
		
		
		snake_dir = (int*)malloc(sizeof(int)*2);
		snake_dir[0] = y_po;
		snake_dir[1] = x_po;
		snake[y_po][x_po] = 1;
		que->push(snake_dir);

		if(apples[y_po][x_po] == 1)
		{
			apples[y_po][x_po] = 0;
		}
		else
		{
			snake_dir = que->front();
			que->pop();
			snake[snake_dir[0]][snake_dir[1]] = 0;
			free(snake_dir);
		}
		if(time == count) // last move
		{
			dir = c=='D'?(dir+1)%4:(dir+3)%4;
			if (l > 0)
			{
				scanf("%d %c", &time, &c);
			l--;
			}
		}
	}	
	return 0;
}
