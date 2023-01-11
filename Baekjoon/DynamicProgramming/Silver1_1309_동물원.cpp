#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int divider = 9901;
	vector<int> results;

	cin >> N;
	results.resize(N+1);
	results[0] = 1;
	results[1] = 3;
	for (int i = 2; i <= N; ++i)
		results[i] = (results[i - 1] * 2 % divider + results[i - 2] % divider) % divider;

	cout << results[N];

	return 0;
}