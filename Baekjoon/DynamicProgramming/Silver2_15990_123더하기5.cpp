/*
문제
	정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다. 단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.

		1+2+1
		1+3
		3+1

	정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
	첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 100,000보다 작거나 같다.

출력
	각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T = 0;
	int divider = 1000000009;
	int max = 0;
	vector<vector<unsigned long long>> answer;
	vector<int> number;

	cin >> T;
	number.resize(T);
	for (int i = 0; i < T; ++i)
	{
		cin >> number[i];
		if (max < number[i])
			max = number[i];
	}
	answer.resize(max+1);

	answer[0].resize(4);

	for (int i = 0; i <= 3; ++i)
		answer[0][i] = 0;
	
	for (int i = 1; i <= 3; ++i)
	{
		answer[i].resize(4);
		answer[i][0] = 1;
		for (int j = 1; j <= 3; ++j)
			answer[i][j] = i == j ? 1 : 0;
	}
	answer[3][1] = 1;
	answer[3][2] = 1;
	answer[3][0] = 3;

	for (int i = 4; i <= max; ++i)
	{
		answer[i].resize(4);		
		answer[i][1] = (answer[i - 1][2] + answer[i - 1][3]) % divider;
		answer[i][2] = (answer[i - 2][1] + answer[i - 2][3]) % divider;
		answer[i][3] = (answer[i - 3][1] + answer[i - 3][2]) % divider;
		answer[i][0] = (answer[i][1] + answer[i][2] + answer[i][3]) % divider;
	}

	for (int i = 0; i < T; ++i)
		cout << answer[number[i]][0] << '\n';

	return 0;
}