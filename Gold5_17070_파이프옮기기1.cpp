#include <iostream>
#include <vector>

using namespace std;

/*
	�̵� ���
	�������� �׻� 2���� ���ӵ� ĭ�� ����.
	������ ���� / ���� / ���ϴ� �밢��
	- ���� : �������� �б� / ���ϴ����� �о �밢�� �����
	- ���� : �ϴ����� �б� / ���ϴ����� �о �밢�� �����
	- �밢�� : �������� �о� ���η� ����� / �ϴ����� �о� ���η� �����
				���ϴ����� �б�

	ó���� �������� (1,1)�� (1,2)�� �����ϰ� �ִ� ���� �������̰�,
	�� �������� ���� N,N���� �̵���Ű�� ����� ���� ���ϱ�.

	ù° �ٿ� ���� ũ�� N(3<=N<=16)�� �־�����
	��° �ٺ��� N���� �ٿ� ���� ���°� �־���. �� ĭ�� 0, ���� 1
	(1,1)�� (1,2)�� �׻� �� ĭ.

	�̵���ų �� ���� ��쿡�� 0

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
			// ������ �Ѿ�� ��
			if (tip[PIPE_END][Y] + 1 >= N)
				return;

			// ������ ������ �������� ��
			if (tip[PIPE_END][X] == N - 1 && tip[PIPE_END][Y]+1 == N - 1)
				++count;
			else
			{	
				// �������� �̵� ������ ��
				if (home[tip[PIPE_END][X]][tip[PIPE_END][Y] + 1] == 0)
				{
					tip[PIPE_START][Y] += 1;
					tip[PIPE_END][Y] += 1;
					FindEnd(home, tip, STATE::HORIZONTAL, count);

					// �밢������ �̵� ������ ��
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
			// ������ �Ѿ�� ��
			if (tip[PIPE_END][X] + 1 >= N)
				return;

			// ������ ������ �������� ��
			if (tip[PIPE_END][X]+1 == N - 1 && tip[PIPE_END][Y] == N - 1)
				++count;
			else
			{
				// �ϴ����� �̵� ������ ��
				if (home[tip[PIPE_END][X]+1][tip[PIPE_END][Y]] == 0)
				{
					tip[PIPE_START][X] += 1;
					tip[PIPE_END][X] += 1;
					FindEnd(home, tip, STATE::VERTICAL, count);

					// �밢������ �̵� ������ ��
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
			// ������ �Ѿ�� ��
			if (tip[PIPE_END][X] + 1 >= N && tip[PIPE_END][Y] + 1 >= N)
				return;

			// ������ ������ �������� ��
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