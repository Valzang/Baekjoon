#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	unsigned int resultCount;
	vector<int> coinValues;
	vector<int> coinCounts;	

	cin >> N >> K;
	coinCounts.assign(N, 0);

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		coinValues.push_back(temp);
	}


	for (int i = 0; i < N; ++i)
	{
		int portion = K / coinValues[i];
		if (K % coinValues[i] == 0)
			coinCounts[i] = portion;
		else
		{
			int leftValue = K - portion * coinValues[i];
			for (int j = i; j >= 0; --j)
			{

			}
		}
	}

	return 0;
}