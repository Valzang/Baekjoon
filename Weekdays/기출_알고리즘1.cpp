#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class DIRECTION { UP, RIGHT, DOWN, LEFT };

vector<vector<int>> office;
vector<string> moveOrder;

int N = 0;
int dustCount = 0;

void Move(string order, DIRECTION &dir, int& r, int& c)
{
	if (order == "go")
	{
		switch (dir)
		{
			case DIRECTION::UP:
				if (r > 0 && office[r - 1][c] != -1)
				{
					r -= 1;
					dustCount += office[r][c];
					office[r][c] = 0;
				}
				break;
			case DIRECTION::DOWN:
				if (r < N-1 && office[r + 1][c] != -1)
				{
					r += 1;
					dustCount += office[r][c];
					office[r][c] = 0;
				}
				break;
			case DIRECTION::LEFT:
				if (c > 0 && office[r][c-1] != -1)
				{
					c -= 1;
					dustCount += office[r][c];
					office[r][c] = 0;
				}
				break;
			case DIRECTION::RIGHT:
				if (c < N-1 && office[r][c + 1] != -1)
				{
					c += 1;
					dustCount += office[r][c];
					office[r][c] = 0;
				}
				break;
		}		
	}
	else if (order == "left")
		dir = dir == DIRECTION::UP ? DIRECTION::LEFT : DIRECTION((int)dir - 1);
	else if (order == "right")
		dir = dir == DIRECTION::LEFT ? DIRECTION::UP : DIRECTION((int)dir + 1);
}

void Activate(int r, int c)
{
	dustCount = office[r][c];
	office[r][c] = 0;
	DIRECTION curDirection = DIRECTION::UP;

	for (int i = 0; i < moveOrder.size(); ++i)
		Move(moveOrder[i], curDirection, r, c);

	cout << '\n' << "°á°ú : " << dustCount << '\n';
}


int main()
{
	int r = 1, c = 0;

	cin >> N;
	office.resize(N);
	for (int i = 0; i < N; ++i)
	{
		office[i].resize(N);
		for (int j = 0; j < N; ++j)
			cin >> office[i][j];
	}

	cin >> r >> c;
	while (true)
	{
		string temp = "";
		cin >> temp;
		if (temp != "go" && temp != "right" && temp != "left")
			break;
		moveOrder.push_back(temp);
	}

	Activate(r, c);


	return 0;
}