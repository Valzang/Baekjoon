#include <iostream>
#include <vector>

using namespace std;

int result = -1;

vector<vector<int>> board;
vector<vector<bool>> check;
vector<vector<int>> maxResult;
int MAX_ROW = 4;
int MAX_COL = 4;


void solution(int row, int col, int& curNum, int max = 0)
{
	check[row][col] = true;
	bool isNoWay = false;
	if (row < MAX_ROW - 1 && !check[row + 1][col] && board[row+1][col] == board[row][col])
	{
		check[row + 1][col] = true;
		solution(row + 1, col, curNum, max+1);
		check[row + 1][col] = false;
		isNoWay = true;
	}
	if (row > 0 && !check[row - 1][col] && board[row - 1][col] == board[row][col])
	{
		check[row - 1][col] = true;
		solution(row - 1, col, curNum, max + 1);
		check[row - 1][col] = false;
		isNoWay = true;
	}
	if (col < MAX_COL - 1 && !check[row][col + 1] && board[row][col + 1] == board[row][col])
	{
		check[row][col + 1] = true;
		solution(row, col + 1, curNum, max + 1);
		check[row][col + 1] = false;
		isNoWay = true;
	}
	if (col > 0 && !check[row][col - 1] && board[row][col - 1] == board[row][col])
	{
		check[row][col - 1] = true;
		solution(row, col - 1, curNum, max + 1);
		check[row][col - 1] = false;
		isNoWay = true;
	}

	if (!isNoWay)
		curNum = curNum < max + 1 ? max + 1 : curNum;
	check[row][col] = false;
}

int main()
{
	int answer = -1;
	board.resize(MAX_ROW);
	maxResult.resize(MAX_ROW);
	check.resize(MAX_ROW);
	for (int i = 0; i < MAX_ROW; ++i)
	{
		board[i].resize(MAX_COL);
		maxResult[i].resize(MAX_COL);
		check[i].resize(MAX_COL);
		for (int j = 0; j < MAX_COL; ++j)
			cin >> board[i][j];
	}

	for (int i = 0; i < MAX_ROW; ++i)
	{
		for (int j = 0; j < MAX_COL; ++j)
		{
			solution(i, j, maxResult[i][j]);
			if (answer < maxResult[i][j])
				answer = maxResult[i][j];
		}
	}

	cout << (answer == 1 ? -1 : answer) << '\n';

	return 0;
}