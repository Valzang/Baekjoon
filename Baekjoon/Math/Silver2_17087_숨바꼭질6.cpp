/*

문제
	수빈이는 동생 N명과 숨바꼭질을 하고 있다. 
	수빈이는 현재 점 S에 있고, 동생은 A1, A2, ..., AN에 있다.
	
	수빈이는 걸어서 이동을 할 수 있다. 
	수빈이의 위치가 X일때 걷는다면 1초 후에 X+D나 X-D로 이동할 수 있다. 
	수빈이의 위치가 동생이 있는 위치와 같으면, 동생을 찾았다고 한다.
	
	모든 동생을 찾기위해 D의 값을 정하려고 한다. 가능한 D의 최댓값을 구해보자.

입력
	첫째 줄에 N(1 ≤ N ≤ 105)과 S(1 ≤ S ≤ 109)가 주어진다. 
	둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다. 
	동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.

출력
	가능한 D값의 최댓값을 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b = 0)
{
	if (b <= 0)
		return a;
	return GCD(b, a % b);
}

int main()
{
	int N = 0, S = 0;
	int gcd = 0;
	vector<int> bros;

	cin >> N >> S;
	bros.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> bros[i];
		bros[i] = S > bros[i] ? S - bros[i] : bros[i] - S;
		gcd = gcd != 0 ? GCD(gcd, bros[i]) : bros[i];
	}

	cout << gcd;

	return 0;
}