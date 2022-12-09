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
		fill(cal.begin(), cal.end(), 0);
	}

	DigitResult(int num)
	{
		cal.reserve(100);
		fill(cal.begin(), cal.end(), 0);

		string strNum = to_string(num);
		for (int i = 0; i < strNum.size(); ++i)
		{
			cal[i] = num % 10;
			num /= 10;
		}
	}

	// 1의 자릿수가 0번부터 채워짐.

	bool Calculate(vector<int> tempCal)
	{
		if (tempCal[tempCal.size() - 1] >= 10)
			return false;

		for (int i = 0; i < tempCal.size()-1; ++i)
		{
			string num = to_string(tempCal[i]);
			while (num.size() != 1 || num != "0")
			{
				// 0이나 1 이외가 나왔을 시
				if ((int)num.back() - 48 > 1)
					return false;
				// 가장 큰 자릿수의 수를 해당 위치로 옮겨줌.
				tempCal[i + num.size() - 1] += (int)num.front() - 48;
				num = to_string(tempCal[i] / 10);			
			}			
		}
		if (tempCal[tempCal.size() - 1] < 10)
		{
			for (int i = tempCal.size() - 1; i >= 0; --i)
			{
				if (tempCal[i] != 0)
					cout << tempCal[i];
			}
			cout << '\n';
			return true;
		}
		return false;
	}

	bool Multiply(int val)
	{
		vector<int> tempCal = cal;
		for (int i = 0; i < tempCal.size(); ++i)
			tempCal[i] *= val;
		
		return Calculate(tempCal);
	}
};

void Solution(int N)
{
	int result = -1;
	DigitResult digitResult(N);
	vector<int> divNum;
	// 끝자리가 0이나 1이 나오도록 숫자 제한.
	// divNum도 한 자리 한자리로 해야함.
	for (int i = 1; i <= 9; ++i)
	{
		if ((N * i) % 10 <= 1)
			divNum.push_back(i);
	}

	int curIdx = 0;
	while (true)
	{
		if (digitResult.Multiply(divNum[curIdx++]))
			break;
		if (curIdx == divNum.size())
		{
			for (int i = 0; i < divNum.size(); ++i)
			{
				divNum[i] += 10;
			}
			curIdx = divNum[0];
		}
	}


	if (result == -1)
		cout << "BRAK" << '\n';
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