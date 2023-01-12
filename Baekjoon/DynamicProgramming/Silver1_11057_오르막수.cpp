/*
문제
	오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 
	이때, 인접한 수가 같아도 오름차순으로 친다.	

	예를 들어, 2234와 3678, 11119는 오르막 수이지만, 2232, 3676, 91111은 오르막 수가 아니다.	

	수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 
	수는 0으로 시작할 수 있다.

입력
	첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

출력
	첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

*/

#include <iostream>

using namespace std;

int results[1001][10];
int total[1001];

int main()
{
	int N;
	int divider = 10007;	

	for (int i = 0; i <= 9; ++i)
	{
		results[1][i] = 1;
		total[1] += 1;
		results[2][i] = 10 - i;
		total[2] += results[2][i];
	}

	cin >> N;

	for (int i = 3; i <= N; ++i)
	{
		results[i][0] = total[i - 1];
		total[i] = total[i - 1];
		for (int j = 1; j <= 9; ++j)
		{
			results[i][j] = (results[i][j-1] % divider - results[i - 1][j - 1] % divider + divider) % divider;
			total[i] = (total[i] + results[i][j]) % divider;
		}		
	}

	cout << total[N];
	return 0;
}