#include <iostream>
#include <vector>

using namespace std;

int N = 0;

enum class STATE
{
	HORIZONTAL,
	VERTICAL,
	DIAGONAL
};

enum PIPE
{
	PIPE_START,
	PIPE_END,
};

enum PIPE_POS
{
	X,
	Y,
};

void Print(int **home, int tip[2][2])
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == tip[PIPE_START][X] && j == tip[PIPE_START][Y]
				|| i == tip[PIPE_END][X] && j == tip[PIPE_END][Y])
				cout << "= ";
			else
				cout << home[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void FindEnd(int **home, int tip[2][2], STATE curState, int& count, int order)
{
	switch (curState)
	{
		case STATE::HORIZONTAL:
			// 마지막 지점에 도달했을 때
			if (tip[PIPE_END][X] <= N && tip[PIPE_END][Y] + 1 <= N)						
			{
				// 우측으로 이동 가능할 때
				if (home[tip[PIPE_END][X]][tip[PIPE_END][Y] + 1] == 0)
				{
					tip[PIPE_START][Y] += 1;
					tip[PIPE_END][Y] += 1;
					//cout << order << " 가로 : 가로 이동" << '\n';
					//Print(home, tip);
					if (tip[PIPE_END][X] == N && tip[PIPE_END][Y]== N)
						++count;
					FindEnd(home, tip, STATE::HORIZONTAL, count, order + 1);
					tip[PIPE_START][Y] -= 1;
					tip[PIPE_END][Y] -= 1;

					// 대각선으로 이동 가능할 때
					if (tip[PIPE_END][X] + 1 <= N
						&& home[tip[PIPE_END][X] + 1][tip[PIPE_END][Y]+1] == 0
						&& home[tip[PIPE_END][X] + 1][tip[PIPE_END][Y]] == 0)
					{
						//cout << order << " 가로 : 대각선 이동" << '\n';
						tip[PIPE_START][Y] += 1;
						tip[PIPE_END][Y] += 1;
						tip[PIPE_END][X] += 1;
						//Print(home, tip);
						if (tip[PIPE_END][X] == N && tip[PIPE_END][Y] == N)
							++count;
						FindEnd(home, tip, STATE::DIAGONAL, count, order + 1);
						tip[PIPE_START][Y] -= 1;
						tip[PIPE_END][Y] -= 1;
						tip[PIPE_END][X] -= 1;
					}
				}
			}
			break;
		case STATE::VERTICAL:
			// 마지막 지점에 도달했을 때
			if (tip[PIPE_END][X] + 1 <= N && tip[PIPE_END][Y] <= N)
			{
				// 하단으로 이동 가능할 때
				if (home[tip[PIPE_END][X]+1][tip[PIPE_END][Y]] == 0)
				{
					tip[PIPE_START][X] += 1;
					tip[PIPE_END][X] += 1;
					//cout << order << " 세로 : 세로 이동" << '\n';
					//Print(home, tip);
					if (tip[PIPE_END][X] == N && tip[PIPE_END][Y] == N)
						++count;
					FindEnd(home, tip, STATE::VERTICAL, count, order + 1);
					tip[PIPE_START][X] -= 1;
					tip[PIPE_END][X] -= 1;

					// 대각선으로 이동 가능할 때
					if (tip[PIPE_END][Y] + 1 <= N
						&& home[tip[PIPE_END][X]+1][tip[PIPE_END][Y]+1] == 0
						&& home[tip[PIPE_END][X]][tip[PIPE_END][Y]+1] == 0)
					{
						//cout << order << " 세로 : 대각선 이동" << '\n';
						tip[PIPE_START][X] += 1;
						tip[PIPE_END][X] += 1;
						tip[PIPE_END][Y] += 1;
						//Print(home, tip);				
						if (tip[PIPE_END][X] == N && tip[PIPE_END][Y] == N)
							++count;
						FindEnd(home, tip, STATE::DIAGONAL, count, order + 1);
						tip[PIPE_START][X] -= 1;
						tip[PIPE_END][X] -= 1;
						tip[PIPE_END][Y] -= 1;
					}
				}
			}
			break;
		case STATE::DIAGONAL:
			// 범위를 넘어섰을 때
			if (tip[PIPE_END][X] + 1 <= N || tip[PIPE_END][Y] + 1 <= N)
			{
				// 우측으로 이동 가능할 때
				if (tip[PIPE_END][Y] + 1 <= N && home[tip[PIPE_END][X]][tip[PIPE_END][Y] + 1] == 0)
				{
					tip[PIPE_START][X] += 1;
					tip[PIPE_START][Y] += 1;
					tip[PIPE_END][Y] += 1;
					//cout << order << " 대각선 : 가로 이동" << '\n';
					//Print(home, tip);
					if (tip[PIPE_END][X] == N && tip[PIPE_END][Y] == N)
						++count;
					FindEnd(home, tip, STATE::HORIZONTAL, count, order + 1);
					tip[PIPE_START][X] -= 1;
					tip[PIPE_START][Y] -= 1;
					tip[PIPE_END][Y] -= 1;
				}

				// 하단으로 이동 가능할 때
				if (tip[PIPE_END][X] + 1 <= N && home[tip[PIPE_END][X] + 1][tip[PIPE_END][Y]] == 0)
				{
					tip[PIPE_START][Y] += 1;
					tip[PIPE_START][X] += 1;
					tip[PIPE_END][X] += 1;
					//cout << order << " 대각선 : 세로 이동" << '\n';
					//Print(home, tip);
					if (tip[PIPE_END][X] == N && tip[PIPE_END][Y] == N)
						++count;
					FindEnd(home, tip, STATE::VERTICAL, count, order + 1);
					tip[PIPE_START][Y] -= 1;
					tip[PIPE_START][X] -= 1;
					tip[PIPE_END][X] -= 1;
				}
				
				// 대각선으로 이동 가능할 때
				if (tip[PIPE_END][X] + 1 <= N && tip[PIPE_END][Y] + 1 <= N
					&& home[tip[PIPE_END][X] + 1][tip[PIPE_END][Y]] == 0
					&& home[tip[PIPE_END][X]][tip[PIPE_END][Y]+1] == 0
					&& home[tip[PIPE_END][X]+1][tip[PIPE_END][Y] + 1] == 0)
				{
					tip[PIPE_START][Y] += 1;
					tip[PIPE_START][X] += 1;
					tip[PIPE_END][Y] += 1;
					tip[PIPE_END][X] += 1;
					//cout << order << " 대각선 : 대각선 이동" << '\n';
					//Print(home, tip);
					if (tip[PIPE_END][X] == N && tip[PIPE_END][Y] == N)
						++count;
					FindEnd(home, tip, STATE::DIAGONAL, count, order +1);
					tip[PIPE_START][Y] -= 1;
					tip[PIPE_START][X] -= 1;
					tip[PIPE_END][Y] -= 1;
					tip[PIPE_END][X] -= 1;
				}
			}
			break;
	}
}

int main()
{
	cin >> N;
	int count = 0;
	int tip[2][2] = { { 1, 1 }, { 1, 2 } };

	int** home = new int* [N+1];
	for (int i = 0; i < N+1; ++i)
	{
		home[i] = new int[N+1];
		memset(home[i], 0, sizeof(int) * N);
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> home[i][j];
		}
	}
	//cout << "\n\n=================초기 시작==================\n";
	//Print(home, tip);
	FindEnd(home, tip, STATE::HORIZONTAL, count, 0);

	//cout << "이동가능 경우 : " << count << '\n';
	cout << count << '\n';


	for (int j = 0; j < N+1; ++j)
	{
		delete[] home[j];
	}
	delete[] home;

	return 0;
}