#include <iostream>
#include <crtdbg.h>

using namespace std;


#define COLUMN 8
#define ROW 8

int maxGunner = 0;
int maxGunnerCount = 0;

enum STATE
{
	EMPTY,
	WALL,
	GUNNER
};


void CountMaxGunner(int **room, int row, int col, int _maxGunner)
{
	if (col >= COLUMN)
	{		
		col = 0;
		++row;
		if (row >= ROW)
		{
			if (_maxGunner > maxGunner)
			{
				maxGunner = _maxGunner;
				maxGunnerCount = 1;
			}
			else if (_maxGunner == maxGunner)
				++maxGunnerCount;
			else
				return;
			
			// ��� ��¿�
			
			for (int i = 0; i < ROW; ++i)
			{
				for (int j = 0; j < COLUMN; ++j)
				{
					cout << (room[i][j] == EMPTY ? "\u25A1" : room[i][j] == GUNNER ? "\u2642" : "\u25A0");
				}
				cout << '\n';
			}
			cout << "���� �ִ� �����̼� : " << maxGunner << '\n';
			
			return;
		}
	}

	bool k1Check = room[row][col] == WALL;
	bool k2Check = room[row][col] == WALL;

	bool canSet = true;

	// �� üũ
	for (int k1 = row - 1; k1 >= 0; --k1)
	{
		if (room[k1][col] == WALL)
		{
			canSet = true;
			break;
		}
		else if (room[k1][col] == GUNNER)
		{
			if (!k1Check)
			{
				canSet = false;
				break;
			}
			else
				k1Check = false;
		}
	}

	// �� üũ
	if (canSet)
	{
		for (int k2 = col - 1; k2 >= 0; --k2)
		{
			if (room[row][k2] == WALL)
			{
				canSet = true;
				break;
			}
			else if (room[row][k2] == GUNNER)
			{
				if (!k2Check)
				{
					canSet = false;
					break;
				}
				else
					k2Check = false;
			}
		}
	}

	// ���� ��� �ְ�, ������ ��ġ�� ������ ���� �� ������ ��ġ
	if (canSet && room[row][col]==EMPTY)
	{
		room[row][col] = GUNNER;
		CountMaxGunner(room, row, col + 1, _maxGunner + 1);
	}
	if(room[row][col] == GUNNER)
		room[row][col] = EMPTY;

	// ������ ��ġ �����ϴ��� ��ġ ��ŵ
	CountMaxGunner(room, row, col + 1, _maxGunner);

}


int main()
{
	int** room = new int* [ROW];
	for (int i = 0; i < ROW; ++i)
	{
		room[i] = new int[COLUMN];
		memset(room[i], EMPTY, sizeof(int) * ROW);
	}

	// �־��� ���� =====================================

	room[0][1] = WALL;	room[0][3] = WALL;	room[0][5] = WALL;	room[0][7] = WALL;
	room[1][5] = WALL;
	room[2][0] = WALL; room[2][2] = WALL; room[2][5] = WALL; room[2][7] = WALL;
	room[4][3] = WALL;
	room[5][5] = WALL; room[5][7] = WALL;
	room[6][1] = WALL;
	room[7][4] = WALL; room[7][6] = WALL;

	// �ʱ� ��� ��¿� =====================================
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			cout << (room[i][j] == EMPTY ? "\u25A1" : room[i][j] == GUNNER ? "\u2642" : "\u25A0");
		}
		cout << '\n';
	}
	cout << '\n';
	// ===========================================

	CountMaxGunner(room, 0, 0, maxGunner);

	cout << "�ִ� ������ �� : " << maxGunner << "��" << '\n'
	<< "��ġ ������ : " << maxGunnerCount << "����" << '\n';

	for (int i = 0; i < ROW; ++i)
		delete[] room[i];

	delete[] room;

	_CrtDumpMemoryLeaks();

	return 0;
}