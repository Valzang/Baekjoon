#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> curMap;
vector<vector<bool>> check;

queue<pair<int, pair<int, int>>> Q;

int R, C;

void Check(int row, int col, int curDist)
{
	if (row <= 0 || row > R || col <= 0 || col > C || check[row][col])
		return;

	check[row][col] = true;
	if (curMap[row][col] == 'F')
	{
		cout << curDist << '\n';
		exit(0);
	}

	if(curMap[row][col] != 'X')
		Q.push(make_pair(curDist, make_pair(row, col)));
}

void DP(int row, int col)
{
	Q.push(make_pair(0, make_pair(row, col)));
	while (!Q.empty())
	{
		int curDist = Q.front().first;
		int curRow = Q.front().second.first;
		int curCol = Q.front().second.second;

		Q.pop();
		Check(curRow + 1, curCol, curDist + 1);
		Check(curRow - 1, curCol, curDist + 1);
		Check(curRow, curCol + 1, curDist + 1);
		Check(curRow, curCol - 1, curDist + 1);


	}
}


int main()
{
	int startRow = 0, startCol = 0;
	cin >> R >> C;
	curMap.resize(R + 1);
	check.resize(R + 1);
	for (int i = 1; i <= R; ++i)
	{
		curMap[i].resize(C + 1);
		check[i].resize(C + 1);
		for (int j = 1; j <= C; ++j)
		{
			cin >> curMap[i][j];
			if (curMap[i][j] == 'S')
			{
				startRow = i;
				startCol = j;
			}
		}
	}

	DP(startRow, startCol);
	


	return 0;
}

/*

7 8
00000000
0XXX0XX0
00000XX0
0S0X0XXF
000X0000
000X0000
00000000

10

*/