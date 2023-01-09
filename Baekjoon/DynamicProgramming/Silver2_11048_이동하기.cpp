#include <iostream>

using namespace std;

int maze[1001][1001];
int maxCandy[1001][1001];

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> maze[i][j];
			int max = maxCandy[i - 1][j] > maxCandy[i][j - 1] ? maxCandy[i - 1][j] : maxCandy[i][j - 1];
			max = max > maxCandy[i - 1][j - 1] ? max : maxCandy[i - 1][j - 1];
			maxCandy[i][j] = maze[i][j] + max;
		}
	}

	cout << maxCandy[N][M];

	return 0;
}