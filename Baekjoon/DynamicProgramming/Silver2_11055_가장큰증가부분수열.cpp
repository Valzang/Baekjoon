/*

문제
	수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.	
	예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우,
	합이 가장 큰 증가 부분 수열은 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 이고, 합은 113이다.

입력
	첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
	
	둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
	첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int answer = 0;
	vector<int> result;
	vector<int> progression;

	cin >> N;
	progression.resize(N + 1);
	result.resize(N + 1);

	for (int i = 1; i <= N; ++i)
		cin >> progression[i];

	for (int i = N; i >= 0; --i)
	{
		int curNum = progression[i];
		int startNum = curNum;
		result[i] = curNum;
		for (int j = i+1; j <= N; ++j)
		{			
			if (progression[j] > startNum && (progression[j] <= curNum || startNum == curNum))
			{
				curNum = progression[j];
				int sum = startNum + result[j];
				result[i] = result[i] > sum ? result[i] : sum;
			}
		}
		if (answer < result[i])
			answer = result[i];
	}

	cout << answer;


	return 0;
}