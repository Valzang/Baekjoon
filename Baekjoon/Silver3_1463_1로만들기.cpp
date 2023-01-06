/*
문제
	정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
	- X가 3으로 나누어 떨어지면, 3으로 나눈다.
	- X가 2로 나누어 떨어지면, 2로 나눈다.
	- 1을 뺀다.
	정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
	첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

출력
	첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

*/

#include <iostream>

using namespace std;

int GetMin(int A, int B, int C)
{
	int min = A > B ? B : A;
	return min > C ? C : min;
}

int main()
{
	int N;
	int *min;

	cin >> N;
	min = new int[N+1];
	fill_n(min, N+1, 1000001);
	min[1] = 0;

	for (int i = 2; i <= N; ++i)
		min[i] = GetMin( i % 3 == 0 ? min[i/3] : min[i], i % 2 == 0 ? min[i / 2] : min[i], min[i-1]) + 1;

	cout << min[N];

	delete[] min;

	return 0;
}