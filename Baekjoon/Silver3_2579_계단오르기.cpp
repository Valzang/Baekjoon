#include <iostream>

using namespace std;

int Max(int A, int B)
{
	return A > B ? A : B;
}


int main()
{
	int stairCounts = 0;
	int stairValues[302] = { 0, };
	int maxPoints[302][2] = { 0, };

	cin >> stairCounts;

	for (int i = 2; i <= stairCounts+1; ++i)
	{
		cin >> stairValues[i];
		maxPoints[i][0] = stairValues[i] + Max(maxPoints[i - 2][0], maxPoints[i - 2][1]);
		maxPoints[i][1] = stairValues[i] + maxPoints[i - 1][0];
	}

	cout << Max(maxPoints[stairCounts+1][0], maxPoints[stairCounts+1][1]);

	return 0;
}

/*

¹Ý·Ê
10
3 5 10 9 2 1 2 5 2 9
Á¤´ä : 37



*/