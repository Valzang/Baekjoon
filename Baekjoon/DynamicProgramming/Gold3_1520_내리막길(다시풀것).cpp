#include <iostream>
#include <stack>

using namespace std;

int N, M;
int heights[501][501];
int passed[501][501];

int DFS(int row, int col)
{
	if (passed[row][col] != -1)
		return passed[row][col];

	if (row == M && col == N)
		return 1;

	passed[row][col] = 0;

	int curNum = heights[row][col];

	if (row > 1 && heights[row - 1][col] < curNum)
		passed[row][col] += DFS(row - 1, col);
	if (row < M && heights[row + 1][col] < curNum)
		passed[row][col] += DFS(row + 1, col);
	if (col > 1 && heights[row][col - 1] < curNum)
		passed[row][col] += DFS(row, col - 1);
	if (col < N && heights[row][col + 1] < curNum)
		passed[row][col] += DFS(row, col + 1);

	return passed[row][col];

}

int main()
{
	cin >> M >> N;

	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> heights[i][j];
			passed[i][j] = -1;
		}
	}
	
	cout << DFS(1,1);

	return 0;
}