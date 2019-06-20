#include <stdio.h>
#define START 100

int channalcount(int, int[10]);

int main(int argc, char const *argv[])
{
	int wantchannal;
	int count;
	int errcount, errnum;
	int buttonerr[10] = {0}; // 0 is no trouble 1 is trouble

	scanf("%d", &wantchannal);
	scanf("%d", &errcount);
	if (errcount == 10) // all button is err then only use + or -
	{	
		count = ((wantchannal-START > 0) ? wantchannal-START : START-wantchannal);
		printf("%d\n", count);
		return 0;
	}

	while(errcount--) //find err botton
	{
		scanf("%d", &errnum); // input err button
		buttonerr[errnum] = 1;
	}
	count = channalcount(wantchannal, buttonerr); // find click num
	printf("%d\n", count);
	return 0;
}

int channalcount(int channal, int err[10])
{
	int clear;
	int count = 0;// ( +or- count) + click channal count
	int compare100 = channal - START; // use only + or - button count
	compare100 = ((compare100 > 0) ? compare100 : -compare100);

	int clickchannal;
	int c_1 = channal; // channal--
	int c_2 = channal; // channal++
	while (count < compare100) // loop until find count
	{
		// c_1 compare
		clear = 1;
		clickchannal = 0;
		for (int i = 1; c_1/i > 0; i *= 10) // c_1 can use not err botton then clear=1
		{
			if (err[c_1%(i*10)/i])
				clear = 0;
			clickchannal++;
		}
		if (clear && (c_1 >= 0)) // if c_1 < 0 is not exist channal
		{
			if (c_1 == 0 && err[0] == 0)
			{
				return 1 + count;
			}
			if (c_1 > 0 && (count+clickchannal) < compare100)
			{
				return count + clickchannal;
			}
		}

		// c_2 compare
		clear = 1;
		clickchannal = 0;
		for (int i = 1; c_2/i > 0; i *= 10) // // c_2 can use not err botton then clear=1
		{
			if (err[c_2%(i*10)/i])
				clear = 0;
			clickchannal++;
		}
		if (c_2 > 0 && clear) // if c_2 < 0 is not exist channal
		{
			if ((count + clickchannal) < compare100)
			{
				return count + clickchannal;
			}
		}

		count++;
		c_1--;
		c_2++;
	}
	return compare100;
}
