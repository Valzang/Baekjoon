#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*

폴란드 왕자 구사과는 다음과 같은 수를 좋아한다.

	- 0과 1로만 이루어져 있어야 한다.
	- 1이 적어도 하나 있어야 한다.
	- 수의 길이가 100 이하이다.
	- 수가 0으로 시작하지 않는다.

예를 들어, 101은 구사과가 좋아하는 수이다.

- 첫째 줄에 테스트 케이스의 개수 T(T < 10)가 주어진다.
- 둘째 줄부터 T개의 줄에는 자연수 N이 한 줄에 하나씩 주어진다. N은 20,000보다 작거나 같은 자연수이다.

- 각각의 테스트 케이스마다 N의 배수이면서, 구사과가 좋아하는 수를 아무거나 출력한다.
	만약, 그러한 수가 없다면 BRAK을 출력한다.

*/

// string을 점점 키워나가면서 중간에 N으로 나눠떨어지면 출력. string의 크기가 100을 초과하면 BRAK 출력
// (A+B)%C = ((A%C) + (B%C)) %C
// (A*B)%C = ((A%C) * (B%C)) %C
// (A*A)%C = ((A%C) * (A%C)) %C
//	=> (10^99)%C = ((10^9 % C)^10)%C
// ex) 123456 % N =>
//		(1* 10^5 + 2*10^4 + 3*10^3 + 4*10^2 + 5*10^1 + 6*10^0) % N
//		=> ((1* 10^5 % N) + (2*10^4 % N ) + ( 3*10^3 % N ) + (4*10^2 % N ) + (5*10^1 %N ) + (6*10^0 % N )) %N

// int max => 2,147,483,647		총 10자리 ( 10^9)
// (10^9)^9
// 10^10 = 10^9 * 10
// 10^99 = (10^9)^9

int PowerModular(int num, int pow, int mod)
{
	int answer = 1;
	while (pow)
	{
		if (pow % 2 == 1)
			answer = (answer * num % mod);
		num = num * num % mod;
		pow /= 2;
	}
	return answer;
}


void Solution(int N)
{
	string stringN = to_string(N);
	string initNum = "1";	
	// N의 자릿수와 동일하게 맞춰주기
	for (int i = 1; i < stringN.size(); ++i)
		initNum.append("0");	

	int totalCount1 = 1;
	int curIndex = 0;
	int totalNumCount = initNum.size();

	int mod = 0;
	while (1)
	{
		for (int i = initNum.size() - 1; i >= 0; --i)
			mod += (initNum[i] % N) * (PowerModular(10, initNum.size() - 1 - i, N) % N);
		if (mod == 0)
		{
			for (int j = 0; j < initNum.size(); ++j)
			{
				cout << initNum[j];
			}
			cout << '\n';
			return;
		}
		else
		{
			if (totalCount1 < totalNumCount)
			{
				if (initNum.back() == 0)
				{
					initNum.pop_back();
					initNum.push_back('1');
					++totalCount1;
				}
				else
				{

				}

			}
		}
	}

}

int main()
{
	int T = 0;

	cin >> T;
	int* N = new int[T];
	memset(N, 0, sizeof(int) * T);

	for (int i = 0; i < T; ++i)
	{
		cin >> N[i];
	}

	delete[] N;

	return 0;
}