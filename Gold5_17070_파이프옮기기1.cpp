#include <iostream>
#include <vector>

using namespace std;

/*
	이동 방법
	파이프는 항상 2개의 연속된 칸을 차지.
	방향은 가로 / 세로 / 우하단 대각선
	- 가로 : 우측으로 밀기 / 우하단으로 밀어서 대각선 만들기
	- 세로 : 하단으로 밀기 / 우하단으로 밀어서 대각선 만들기
	- 대각선 : 우측으로 밀어 가로로 만들기 / 하단으로 밀어 세로로 만들기
				우하단으로 밀기

	처음에 파이프는 (1,1)과 (1,2)를 차지하고 있는 가로 파이프이고,
	이 파이프의 끝을 N,N으로 이동시키는 방법의 개수 구하기.

	첫째 줄에 집의 크기 N(3<=N<=16)가 주어지고
	둘째 줄부터 N개의 줄에 집의 상태가 주어짐. 빈 칸은 0, 벽은 1
	(1,1)과 (1,2)는 항상 빈 칸.

	이동시킬 수 없는 경우에는 0

	// https://www.acmicpc.net/problem/17070

*/


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

void FindEnd(int **home, int tip[2][2], STATE curState, int& count)
{
	switch (curState)
	{
		case STATE::HORIZONTAL:
			// 범위를 넘어섰을 때
			if (tip[PIPE_END][Y] + 1 >= N)
				return;

			// 마지막 지점에 도달했을 때
			if (tip[PIPE_END][X] == N - 1 && tip[PIPE_END][Y]+1 == N - 1)
				++count;
			else
			{	
				// 우측으로 이동 가능할 때
				if (home[tip[PIPE_END][X]][tip[PIPE_END][Y] + 1] == 0)
				{
					tip[PIPE_START][Y] += 1;
					tip[PIPE_END][Y] += 1;
					FindEnd(home, tip, STATE::HORIZONTAL, count);

					// 대각선으로 이동 가능할 때
					if (home[tip[PIPE_END][X] + 1][tip[PIPE_END][Y]] == 0
						&& home[tip[PIPE_END][X] + 1][tip[PIPE_END][Y]-1] == 0)
					{
						tip[PIPE_END][X] += 1;
						FindEnd(home, tip, STATE::DIAGONAL, count);
					}
				}
			}
			break;
		case STATE::VERTICAL:
			// 범위를 넘어섰을 때
			if (tip[PIPE_END][X] + 1 >= N)
				return;

			// 마지막 지점에 도달했을 때
			if (tip[PIPE_END][X]+1 == N - 1 && tip[PIPE_END][Y] == N - 1)
				++count;
			else
			{
				// 하단으로 이동 가능할 때
				if (home[tip[PIPE_END][X]+1][tip[PIPE_END][Y]] == 0)
				{
					tip[PIPE_START][X] += 1;
					tip[PIPE_END][X] += 1;
					FindEnd(home, tip, STATE::VERTICAL, count);

					// 대각선으로 이동 가능할 때
					if (home[tip[PIPE_END][X]][tip[PIPE_END][Y]+1] == 0
						&& home[tip[PIPE_END][X]-1][tip[PIPE_END][Y]+1] == 0)
					{
						tip[PIPE_END][Y] += 1;
						FindEnd(home, tip, STATE::DIAGONAL, count);
					}
				}
			}
			break;
		case STATE::DIAGONAL:
			// 범위를 넘어섰을 때
			if (tip[PIPE_END][X] + 1 >= N && tip[PIPE_END][Y] + 1 >= N)
				return;

			// 마지막 지점에 도달했을 때
			if (tip[PIPE_END][X] + 1 == N - 1 && tip[PIPE_END][Y] == N - 1
				|| tip[PIPE_END][X] == N - 1 && tip[PIPE_END][Y]+1 == N - 1
				|| tip[PIPE_END][X] + 1 == N - 1 && tip[PIPE_END][Y]+1 == N - 1)
				++count;
			else
			{
				
			}
			break;
	}
}

int main()
{
	cin >> N;
	STATE curState = STATE::HORIZONTAL;
	int tip[2][2] = { (1,1) , (1,2) };

	int** home = new int* [N];
	for (int i = 0; i < N; ++i)
	{
		home[i] = new int[N];
		memset(home[i], 0, sizeof(int) * N);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> home[i][j];
		}
	}


	for (int j = 0; j < N; ++j)
	{
		delete[] home[j];
	}
	delete[] home;

	return 0;
}