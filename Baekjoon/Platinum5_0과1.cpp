#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/*

폴란드 왕자 구사과는 다음과 같은 수를 좋아한다.

	- 0과 1로만 이루어져 있어야 한다.
	- 1이 적어도 하나 있어야 한다.
	- 수의 길이가 100 이하이다.
	- 수가 0으로 시작하지 않는다.

예를 들어, 101은 구사과가 좋아하는 수이다.

첫째 줄에 테스트 케이스의 개수 T(T < 10)가 주어진다.
둘째 줄부터 T개의 줄에는 자연수 N이 한 줄에 하나씩 주어진다. N은 20,000보다 작거나 같은 자연수이다.

각각의 테스트 케이스마다 N의 배수이면서, 구사과가 좋아하는 수를 아무거나 출력한다. 만약, 그러한 수가 없다면 BRAK을 출력한다.

*/

class DigitResult
{
	vector<int> cal;

public:

	DigitResult()
	{
		cal.reserve(100);
	}

	void Calculate()
	{
		int zeroCnt = 0;
		for (int i = 0; i < cal.size()-1; ++i)
		{
			string num = to_string(cal[i]);
			while (num.size() != 1 || num != "0")
			{
				cal[i + num.size() - 1] = num.front();
				num = to_string(cal[i] / 10);
			}
			
		}
	}
};

void Solution(int N)
{
	int result = -1;

	vector<int> divNum;
	// 끝자리가 0이나 1이 나오도록 숫자 제한.
	for (int i = 1; i <= 9; ++i)
	{
		if (N % i <= 1)
			divNum.push_back(i);
	}


	if (result == -1)
		cout << "BRAK" << '\n';
	else
		cout << result << '\n';
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