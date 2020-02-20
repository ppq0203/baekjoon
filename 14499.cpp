#include <stdio.h>

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4 

#define ON 0
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define UNDER 5

void map_dice();

int main()
{
	map_dice();
	return 0;
}

void move_dice(int [20][20], int [6], int ,int, int*, int*, int);

void map_dice()
{
	//declare
	int heigh, width, x_po, y_po, order, num, direction;
	scanf("%d %d %d %d %d", &heigh, &width, &y_po, &x_po, &order);

	// initialization
	int maps[20][20] = {0};
	int dice[6] = {0};

	//map setting
	for (int i = 0; i < heigh; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			scanf("%d", &num);
			maps[i][j] = num;
		}
	}
	//dice move
	for (int i = 0; i < order; ++i)
	{
		scanf("%d", &direction);
		move_dice(maps, dice, heigh, width, &x_po, &y_po, direction);
	}
}

void move_dice(int maps[20][20], int dice[6], int heigh ,int width, int *x_po, int *y_po, int direction)
{
	int save;
	switch(direction)
	{
		case RIGHT :
			if((*x_po) == width-1)
				return;
			(*x_po)++;
			save = dice[ON];
			dice[ON] = dice[WEST];
			dice[WEST] = dice[UNDER];
			dice[UNDER] = dice[EAST];
			dice[EAST] = save;
			// printf("RIGHT\n");
			break;
		case LEFT :
			if(*x_po <= 0)
				return;
			(*x_po)--;
			save = dice[ON];
			dice[ON] = dice[EAST];
			dice[EAST] = dice[UNDER];
			dice[UNDER] = dice[WEST];
			dice[WEST] = save;
			// printf("LEFT\n");
			break;
		case UP :
			if(*y_po <= 0)
				return;
			(*y_po)--;
			save = dice[ON];
			dice[ON] = dice[SOUTH];
			dice[SOUTH] = dice[UNDER];
			dice[UNDER] = dice[NORTH];
			dice[NORTH] = save;
			// printf("UP\n");
			break;
		case DOWN :
			if(*y_po == heigh-1)
				return;
			(*y_po)++;
			save = dice[ON];
			dice[ON] = dice[NORTH];
			dice[NORTH] = dice[UNDER];
			dice[UNDER] = dice[SOUTH];
			dice[SOUTH] = save;
			// printf("DOWN\n");
			break;
	}
	// printf("x:%d y:%d map:%d\n", *x_po, *y_po, maps[*y_po][*x_po]);
	if(maps[*y_po][*x_po] != 0)
	{
		dice[UNDER] = maps[*y_po][*x_po];
		maps[*y_po][*x_po] = 0;
	}
	else
	{
		maps[*y_po][*x_po] = dice[UNDER];
	}

	// for (int i = 0; i < 6; ++i)
	// {
	// 	printf("%d ", dice[i]);
	// }
	// printf("\n");
	printf("%d\n", dice[ON]);
}