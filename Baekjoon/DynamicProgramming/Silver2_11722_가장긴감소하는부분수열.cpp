/*

문제
	수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.
	예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 
	가장 긴 감소하는 부분 수열은 A = {30, 20, 10}  이고, 길이는 3이다.

입력
	첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
	둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
	첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> A, pair<int, int> B)
{
	return A.second > B.second;
}

int main()
{
	int N = 0;
	vector<int> A;
	vector<pair<int,int>> result;
	cin >> N;

	A.resize(N);
	result.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		result[i] = make_pair(A[i], 1);
	}

	int max = 1;
	for (int i = N - 2; i >= 0; --i)
	{
		sort(result.begin() + i + 1, result.end(), compare);
		for (int j = i + 1; j < N; ++j)
		{
			if (A[i] > result[j].first)
			{
				result[i].second += result[j].second;
				break;
			}
		}
		if (max < result[i].second)
			max = result[i].second;
	}

	cout << max;

	return 0;
}