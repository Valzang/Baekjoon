#include <iostream>

using namespace std;

int DP[501];

int main()
{
	int N = 0;
	cin >> N;

	for (int i = 5; i <= N; ++i)
	{
		if (i % 5 == 0)
		{
			int x = i;
			int count = 0;
			while (x % 5 == 0)
			{
				x /= 5;
				++count;
			}
			DP[i] = DP[i - 5] + count;
		}
		else
			DP[i] = DP[i - 1];
		
	}

	cout << DP[N];
	

	return 0;
}