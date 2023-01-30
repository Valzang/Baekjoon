/*

문제
	수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
	예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 {10, 20, 30, 50} 이고, 길이는 4이다.

입력
	첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.	
	둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
	첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.	
	둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int> a, vector<int> b)
{
	return (int)a.size() > (int)b.size();
}

int main()
{
	int N = 0;
	vector<int> numbers;
	vector<vector<int>> answer;

	cin >> N;
	numbers.resize(N);
	answer.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	for (int i = N - 1; i >= 0; --i)
	{
		int closeIndex = i;
		for (int j = i+1; j < N; ++j)
		{
			if (numbers[i] < numbers[j] && (int)answer[closeIndex].size() < (int)answer[j].size())
				closeIndex = j;
		}
		answer[i] = answer[closeIndex];
		answer[i].insert(answer[i].begin(), numbers[i]);
	}

	sort(answer.begin(), answer.end(), compare);

	cout << (int)answer[0].size() << '\n';
	for (int i = 0; i < (int)answer[0].size(); ++i)
		cout << answer[0][i] << " ";

	return 0;
}