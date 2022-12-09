#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum class TANK_DIRECTION {	EAST,	NORTH,	WEST,	SOUTH};
enum TANK_POS {W,H};

struct Vec2
{
	int w;	int h;
	Vec2()
	{
		w = 0;	h = 0;
	}
};

vector<string> orderVec;
char** tankMap;

class AbleWay
{
private:
	map<TANK_DIRECTION, bool> ableMap;

public:
	AbleWay(Vec2 tankPos, Vec2 mapSize)
	{
		if (tankPos.h + 1 < mapSize.h)
			ableMap.insert(make_pair(TANK_DIRECTION::EAST, tankMap[tankPos.w][tankPos.h + 1] != '#' && tankMap[tankPos.w][tankPos.h + 1] != 'X'));
		if (tankPos.w + 1 < mapSize.w)
			ableMap.insert(make_pair(TANK_DIRECTION::SOUTH, tankMap[tankPos.w + 1][tankPos.h] != '#' && tankMap[tankPos.w+1][tankPos.h] != 'X'));
		if (tankPos.h - 1 >= 0)
			ableMap.insert(make_pair(TANK_DIRECTION::WEST, tankMap[tankPos.w][tankPos.h - 1] != '#' && tankMap[tankPos.w][tankPos.h-1] != 'X'));
		if (tankPos.w - 1 >= 0)
			ableMap.insert(make_pair(TANK_DIRECTION::NORTH, tankMap[tankPos.w - 1][tankPos.h] != '#' && tankMap[tankPos.w-1][tankPos.h] != 'X'));
	}

	bool CanGo(TANK_DIRECTION dir)
	{
		if (ableMap.find(dir) != ableMap.end())
			return ableMap[dir];
		return false;
	}
};

void Move(const TANK_DIRECTION dir, Vec2 tankPos, Vec2 mapSize, string& curOrder);

void MoveTank(TANK_DIRECTION dir, Vec2 tankPos, Vec2 mapSize, string curOrder)
{
	if (tankMap[tankPos.w][tankPos.h] == 'G')
		orderVec.push_back(curOrder);
	else
	{
		AbleWay able(tankPos, mapSize);
		for (int idx = (int)TANK_DIRECTION::EAST; idx <= (int)TANK_DIRECTION::SOUTH; ++idx)
		{
			int diff = (int)dir - idx;
			diff = diff == 3 ? -1 : diff == -3 ? 1 : diff;
			switch (diff)
			{
				case 0:
					if (able.CanGo((TANK_DIRECTION)idx))
					{
						curOrder.append("F");
						Move((TANK_DIRECTION)idx, tankPos, mapSize, curOrder);
						curOrder.pop_back();
					}
					break;
				case 1:
					if (able.CanGo((TANK_DIRECTION)idx))
					{
						curOrder.append("R"); curOrder.append("F");
						Move((TANK_DIRECTION)idx, tankPos, mapSize, curOrder);
						curOrder.pop_back(); curOrder.pop_back();
					}
					break;
				case -1:
					if (able.CanGo((TANK_DIRECTION)idx))
					{
						curOrder.append("L"); curOrder.append("F");
						Move((TANK_DIRECTION)idx, tankPos, mapSize, curOrder);
						curOrder.pop_back(); curOrder.pop_back();
					}
					break;
				case 2:
				case -2:
					if (able.CanGo((TANK_DIRECTION)idx))
					{
						curOrder.append("L"); curOrder.append("L"); curOrder.append("F");
						Move((TANK_DIRECTION)idx, tankPos, mapSize, curOrder);
						curOrder.pop_back(); curOrder.pop_back(); curOrder.pop_back();
						break;
					}
			}
		}
	}
}

int GetTime(string curResult)
{
	int time = 0;
	for (int j = 0; j < curResult.size(); ++j)
	{
		if (curResult[j] == 'F')
			time += 2;
		else
			++time;
	}
	return time;
}

int main()
{
	string direction;
	TANK_DIRECTION dir;
	Vec2 size;
	Vec2 tankPos;

	// 처음 보고 있는 방향
	cout << "탱크가 처음 보고 있는 방향 입력==========================\n";
	cin >> direction;

	if (direction == "EAST")
		dir = TANK_DIRECTION::EAST;
	else if (direction == "WEST")
		dir = TANK_DIRECTION::WEST;
	else if (direction == "NORTH")
		dir = TANK_DIRECTION::NORTH;
	else
		dir = TANK_DIRECTION::SOUTH;

	// 가로 길이와 세로 길이
	cout << "가로 길이와 세로 길이 입력==========================\n";
	cin >> size.w >> size.h;

	// 맵 할당 후 입력받기
	tankMap = new char* [size.w];
	for (int i = 0; i < size.w; ++i)
		tankMap[i] = new char[size.h];

	cout << "맵 세팅==========================\n";
	for (int i = 0; i < size.w; ++i)
	{
		for (int j = 0; j < size.h; ++j)
		{
			cin >> tankMap[i][j];
			if (tankMap[i][j] == 'T')
			{
				tankPos.w = i;
				tankPos.h = j;
			}
		}
	}

	MoveTank(dir, tankPos, size, "");
	
	cout << "====================================\n";

	if (orderVec.size() != 0)
	{
		string result = orderVec[0];
		int time = GetTime(orderVec[0]);
		cout << "도달하는 방법 총 " << orderVec.size() << " 가지" << '\n';

		for (int i = 1; i < (int)orderVec.size(); ++i)
		{
			int curTime = GetTime(orderVec[i]);
			if (curTime < time)
			{
				result = orderVec[i];
				time = curTime;
			}
		}
		cout << "가장 빠르게 도달한 시간 : " << time << "초\n"
			<< "정답 : " << result << '\n';
	}
	else
		cout << "정답 : X" << '\n';
	
		

	for (int k = 0; k < size.w; ++k)
		delete[] tankMap[k];
	delete[] tankMap;

	return 0;
}

void Move(const TANK_DIRECTION dir, Vec2 tankPos, Vec2 mapSize, string& curOrder)
{
	tankMap[tankPos.w][tankPos.h] = 'X';
	switch (dir)
	{
		case TANK_DIRECTION::EAST:
			++tankPos.h;
			MoveTank(dir, tankPos, mapSize, curOrder);
			--tankPos.h;
			break;
		case TANK_DIRECTION::NORTH:
			--tankPos.w;
			MoveTank(dir, tankPos, mapSize, curOrder);
			++tankPos.w;
			break;
		case TANK_DIRECTION::WEST:
			--tankPos.h;
			MoveTank(dir, tankPos, mapSize, curOrder);
			++tankPos.h;
			break;
		case TANK_DIRECTION::SOUTH:
			++tankPos.w;
			MoveTank(dir, tankPos, mapSize, curOrder);
			--tankPos.w;
			break;
	}
	tankMap[tankPos.w][tankPos.h] = '.';
}