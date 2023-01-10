#include <iostream>
#include <stack>

using namespace std;

int heights[501][501];

int main()
{
	int N, M;
	int result = 0;
	stack<pair<int, int>> ways;

	cin >> M >> N;
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cin >> heights[i][j];
	}

	ways.push(make_pair(1, 1));
	while (!ways.empty())
	{
		int row = ways.top().first;
		int col = ways.top().second;

		if (row == M && col == N)
			++result;

		int curNum = heights[row][col];
		ways.pop();
		if (row > 1 && heights[row - 1][col] < curNum)
			ways.push(make_pair(row - 1, col));
		if (col > 1 && heights[row][col - 1] < curNum)
			ways.push(make_pair(row, col - 1));
		if (row < M && heights[row + 1][col] < curNum)
			ways.push(make_pair(row + 1, col));
		if (col < N && heights[row][col + 1] < curNum)
			ways.push(make_pair(row, col + 1));
	}

	cout << result;


	return 0;
}