/*
문제
	0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
	덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 
	또한 한 개의 수를 여러 번 쓸 수도 있다.

입력
	첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.

출력
	첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.	
*/

#include <iostream>

using namespace std;

int main()
{
	int N, K;
	int **result;

	int divider = 1000000000;

	cin >> N >> K;
	result = new int* [N+1];
	for (int i = 0 ; i<=N; ++i)
		result[i] = new int[K+1];

	for (int i = 2 ; i<=K; ++i)
		result[1][i] = i;
	for (int i = 1; i <= N; ++i)
		result[i][1] = 1;

	for (int j = 2; j <= N; ++j)
	{
		for (int k = 2; k <= K; ++k)
			result[j][k] = (result[j][k-1] + result[j-1][k]) % divider;
	}

	cout << result[N][K];

	for (int i = 0 ; i<=N; ++i)
		delete[] result[i];

	delete[] result;

	return 0;
}