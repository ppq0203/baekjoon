#include <iostream>
#define MAX 500
#define endl '\n'
using namespace std;

int input[MAX+4][MAX+4] = { 0 };

int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int Visit[MAX][MAX] = { 0 };

int maximum = -1;

int sum = 0;
int l;



void tetro(int cnt,int y_idx,int x_idx) {




	if (cnt == 4) {
		/*
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << Visit[i][j] << ' ';
			cout<<endl;
		}
		cout << endl;
		*/
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Visit[i][j] == 1)
					sum += input[i][j];
			}
		}
		*/
	}
	
	else if (cnt < 4) {
		for (int i = 0; i < 4; i++) {
			if (Visit[y_idx][x_idx] == 0) {
				Visit[y_idx][x_idx] = 1;
				sum += input[y_idx][x_idx];
				if (maximum < sum)
					maximum = sum;
				if (y_idx + dy[i] >= 0 && y_idx + dy[i] < MAX && x_idx + dx[i] >= 0 && x_idx + dx[i] < MAX) {
					tetro(cnt + 1, y_idx + dy[i], x_idx + dx[i]);
					
				}
				Visit[y_idx][x_idx] = 0;
				sum -= input[y_idx][x_idx];
			}
		}
	}
}

int main() {
	int sum;
	cin >> N >> M;

	int exception[4][4][4] = {
{
	{1,1,1,0},
	{0,1,0,0},
	{0,0,0,0},
	{0,0,0,0}
	},

{
	{1,0,0,0},
	{1,1,0,0},
	{1,0,0,0},
	{0,0,0,0}
},

{
	{0,1,0,0},
	{1,1,0,0},
	{0,1,0,0},
	{0,0,0,0}
},

{
	{0,1,0,0},
	{1,1,1,0},
	{0,0,0,0},
	{0,0,0,0}
}
	};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> input[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			tetro(0, i, j);
	}

	for (int x = 0; x < 4; x++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sum = 0;
				for (int k = 0; k < 4; k++) {
					for (int q = 0; q < 4; q++) {
						sum += exception[x][k][q] * input[i + k][j + q];
					}
				}
				if (maximum < sum)
					maximum = sum;
			}
		}
	}

	cout << maximum << endl;

	return 0;
}