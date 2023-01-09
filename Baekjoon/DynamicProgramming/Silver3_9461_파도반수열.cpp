#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int testCases = 0;
	vector<int> N;
	int max = 0;
	unsigned long long int PN[101] = { 1,1,1,1,2,2 };

	cin >> testCases;
	
	for (int i = 0; i < testCases; ++i)
	{
		int temp = 0;
		cin >> temp;
		N.push_back(temp);
		if (temp > max)
			max = temp;
	}

	for (int i = 6; i <= max; ++i)
		PN[i] = PN[i - 1] + PN[i - 5];

	for (int i = 0; i < testCases; ++i)
		cout << PN[N[i]] << '\n';

	return 0;
}