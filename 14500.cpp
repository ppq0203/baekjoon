#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tetromino();

int main(int argc, char const *argv[])
{
	tetromino();
	return 0;
}

int base1_calc(int*[500], int*[500], int, int);
int base2_calc(int*[500], int*[500], int, int);
int base3_calc(int*[500], int*[500], int, int);
int base4_calc(int*[500], int*[500], int, int);


void tetromino()
{
	//declare
	int height, width, num, max;
	scanf("%d %d", &height, &width);

	// initialization
	int *maps[500];	// base1 is 1 O O	base3 is 1 O
	int *base1[500];	//			  
	int *base2[500];	// base2 is   1		base4 is  1
	int *base3[500];	//			  O				  O
	int *base4[500];	//			  O
	for (int i = 0; i < 500; ++i)
	{
		maps[i] = (int*)malloc(sizeof(int)*500);
		base1[i] = (int*)malloc(sizeof(int)*500);
		base2[i] = (int*)malloc(sizeof(int)*500);
		base3[i] = (int*)malloc(sizeof(int)*500);
		base4[i] = (int*)malloc(sizeof(int)*500);
		memset(base1[i], 0, sizeof(int)*500);
		memset(base2[i], 0, sizeof(int)*500);
		memset(base3[i], 0, sizeof(int)*500);
		memset(base4[i], 0, sizeof(int)*500);
	}

	//setting
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			scanf("%d", &num);
			maps[i][j] = num;
			if(j > 0)
				base3[i][j-1] = maps[i][j] + maps[i][j-1];
			if(j > 1)
				base1[i][j-2] = maps[i][j] + maps[i][j-1] + maps[i][j-2];
			if(i > 0)
				base4[i-1][j] = maps[i][j] + maps[i-1][j];
			if(i > 1)
				base2[i-2][j] = maps[i][j] + maps[i-1][j] + maps[i-2][j];
		}
	}
	//test
	// for (int i = 0; i < height; ++i)
	// {
	// 	for (int j = 0; j < width; ++j)
	// 	{
	// 		printf("%d ", base4[i][j]);
	// 	}
	// 	printf("\n");
	// }

	//calc
	max = 0;
	num = base1_calc(maps, base1, width, height);
	max = max>num?max:num;
	// printf("base1max:%d\n", num);

	num = base2_calc(maps, base2, width, height);
	max = max>num?max:num;

	// printf("base2max:%d\n", num);
	num = base3_calc(maps, base3, width, height);
	max = max>num?max:num;

	// printf("base3max:%d\n", num);
	num = base4_calc(maps, base4, width, height);
	max = max>num?max:num;

	// printf("base4max:%d\n", num);

	printf("%d\n", max);
}


int base1_calc(int *maps[500], int *base[500], int width, int height)
{
	int num, max = 0;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width-2; ++j)
		{
			if(i > 0)
			{
				for(int k = 0; k < 3; ++k)
				{
					num = base[i][j]+maps[i-1][j+k];	//	O		  O			O
					max = max>num?max:num;				//	1 O O	1 O O	1 O O	
				}
			}
			if(j < width-3)
			{
				num = base[i][j]+maps[i][j+3];			//	1 O O O
				max = max>num?max:num;					//
			}
			if(i < height-1)
			{
				for(int k = 0; k < 3; ++k)
				{								
					num = base[i][j]+maps[i+1][j+k];	//	1 O O	1 O O	1 O O
					max = max>num?max:num;				//	O		  O			O
				}
			}
		}
	}
	return max;
}

int base2_calc(int *maps[500], int *base[500], int width, int height)
{
	int num, max = 0;
	for (int i = 0; i < height-2; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if(j > 0)
			{
				for(int k = 0; k < 3; ++k)
				{										//
					num = base[i][j]+maps[i+k][j-1];	//	O 1		1	  1
					max = max>num?max:num;				//	  O	  O O	  O
				}										//	  O		O	O O
			}
			if(i < height-3)
			{											//	1
				num = base[i][j]+maps[i+3][j];			//	O
				max = max>num?max:num;					//	O
			}											//	O
			if(j < width-1)
			{
				for(int k = 0; k < 3; ++k)
				{										//								
					num = base[i][j]+maps[i+k][j+1];	//	1 O	  1		1
					max = max>num?max:num;				//	O	  O O	O
				}										//	O	  O		O O
			}
		}
	}
	return max;
}

int base3_calc(int *maps[500], int *base[500], int width, int height)
{
	int num, max = 0;
	for (int i = 0; i < height-1; ++i)
	{
		for (int j = 0; j < width-1; ++j)
		{
			num = base[i][j]+maps[i+1][j]+maps[i+1][j+1];		//	1 O
			max = max>num?max:num;								//	O O
			if(j > 0)
			{
				num = base[i][j]+maps[i+1][j-1]+maps[i+1][j];	//	  1 O
				max = max>num?max:num;							//	O O
			}
			if(j < width-2)
			{
				num = base[i][j]+maps[i+1][j+1]+maps[i+1][j+2];	//	1 O
				max = max>num?max:num;							//	  O O
			}
		}
	}
	return max;
}

int base4_calc(int *maps[500], int *base[500], int width, int height)
{
	int num, max = 0;
	for (int i = 0; i < height-1; ++i)
	{
		for (int j = 0; j < width-1; ++j)
		{

			if(i > 0)
			{
				num = base[i][j]+maps[i-1][j+1]+maps[i][j+1];	//	  O
				max = max>num?max:num;							//	1 O
			}													//	O
			if(i < height-2)
			{
				num = base[i][j]+maps[i+1][j+1]+maps[i+2][j+1];	//	1 
				max = max>num?max:num;							//	O O
			}													//	  O
		}
	}
	return max;
}