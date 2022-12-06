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
			
			// 결과 출력용
			
			for (int i = 0; i < ROW; ++i)
			{
				for (int j = 0; j < COLUMN; ++j)
				{
					cout << (room[i][j] == EMPTY ? "\u25A1" : room[i][j] == GUNNER ? "\u2642" : "\u25A0");
				}
				cout << '\n';
			}
			cout << "현재 최대 총잡이수 : " << maxGunner << '\n';
			
			return;
		}
	}

	bool k1Check = room[row][col] == WALL;
	bool k2Check = room[row][col] == WALL;

	bool canSet = true;

	// 행 체크
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

	// 열 체크
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

	// 현재 비어 있고, 총잡이 배치가 가능한 곳일 때 총잡이 배치
	if (canSet && room[row][col]==EMPTY)
	{
		room[row][col] = GUNNER;
		CountMaxGunner(room, row, col + 1, _maxGunner + 1);
	}
	if(room[row][col] == GUNNER)
		room[row][col] = EMPTY;

	// 총잡이 배치 가능하더라도 배치 스킵
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

	// 주어진 조건 =====================================

	room[0][1] = WALL;	room[0][3] = WALL;	room[0][5] = WALL;	room[0][7] = WALL;
	room[1][5] = WALL;
	room[2][0] = WALL; room[2][2] = WALL; room[2][5] = WALL; room[2][7] = WALL;
	room[4][3] = WALL;
	room[5][5] = WALL; room[5][7] = WALL;
	room[6][1] = WALL;
	room[7][4] = WALL; room[7][6] = WALL;

	// 초기 모습 출력용 =====================================
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

	cout << "최대 총잡이 수 : " << maxGunner << "명" << '\n'
	<< "배치 가짓수 : " << maxGunnerCount << "가지" << '\n';

	for (int i = 0; i < ROW; ++i)
		delete[] room[i];

	delete[] room;

	_CrtDumpMemoryLeaks();

	return 0;
}