/*

문제
	2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
	아래 그림은 2×17 직사각형을 채운 한가지 예이다.

입력
	첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
	첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	int divider = 10007;
	vector<int> result;
	cin >> n;

	result.resize(n + 1);
	result[1] = 1;
	for (int i = 2; i <= n; ++i)
		result[i] = (i % 2 == 0 ? result[i - 1] * 2 + 1 : result[i - 1] * 2 - 1) % divider;
	

	cout << result[n];

	return 0;
}