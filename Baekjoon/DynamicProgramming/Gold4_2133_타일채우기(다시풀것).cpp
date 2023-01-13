/*

문제
	3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
	첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
	첫째 줄에 경우의 수를 출력한다.

*/


#include <iostream>

using namespace std;

int main()
{
	int N;
	unsigned long long results[31] = { 0, };

	cin >> N;

	results[0] = 1;
	results[1] = 0;
	results[2] = 3;

	for (int i = 4; i <= N; i+=2)
		results[i] = results[i - 2] * 4 - results[i-4];

	cout << results[N];
	


	return 0;
}