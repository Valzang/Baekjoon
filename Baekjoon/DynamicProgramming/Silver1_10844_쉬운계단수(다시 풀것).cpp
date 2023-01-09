/*

문제
	45656이란 수를 보자.
	이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
	N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
	첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
	첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	unsigned int div = 1000000000;
	unsigned int result[101] = { 0, };
	int counts[101][10] = { 0, };
	
	cin >> N;

	counts[1][0] = 0;
	for (int j = 1; j < 10; ++j)
		counts[1][j] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
				counts[i][j] = counts[i - 1][j + 1] ;
			else if( j== 9)
				counts[i][j] = counts[i - 1][j - 1];
			else
				counts[i][j] = (counts[i - 1][j - 1] % div + counts[i - 1][j + 1] % div) % div;
		}
	}
	for (int i = 0; i <= 9; ++i)
		result[N] = (result[N] % div + counts[N][i]) % div;

	cout << result[N];

	return 0;
}

/*
답지
https://ideone.com/n9K9id
*/