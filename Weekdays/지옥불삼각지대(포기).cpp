#include <iostream>
#include <vector>

using namespace std;

struct Vector2
{
	float x;
	float y;
	Vector2() { x = 0, y = 0; }
};

int main()
{
	int T, N, R;
	Vector2 circle[3];
	vector<vector<Vector2>> shape;

	cin >> T;
	cin >> R >> circle[0].x >> circle[0].y >> circle[1].x >> circle[1].y >> circle[2].x >> circle[2].y;

	for (int i = 0; i < T; ++i)
	{
		int unit = 0;
		cin >> unit;
		shape.resize(unit);
		for (int j = 0; j < unit; ++j)
		{
			int point = 0;
			cin >> point;
			for (int k = 0; k<point; ++k)
				cin >> 
		}
	}
	

	return 0;
}