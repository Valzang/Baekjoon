#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

/*

������ ���� ������� ������ ���� ���� �����Ѵ�.

	- 0�� 1�θ� �̷���� �־�� �Ѵ�.
	- 1�� ��� �ϳ� �־�� �Ѵ�.
	- ���� ���̰� 100 �����̴�.
	- ���� 0���� �������� �ʴ´�.

���� ���, 101�� ������� �����ϴ� ���̴�.

ù° �ٿ� �׽�Ʈ ���̽��� ���� T(T < 10)�� �־�����.
��° �ٺ��� T���� �ٿ��� �ڿ��� N�� �� �ٿ� �ϳ��� �־�����. N�� 20,000���� �۰ų� ���� �ڿ����̴�.

������ �׽�Ʈ ���̽����� N�� ����̸鼭, ������� �����ϴ� ���� �ƹ��ų� ����Ѵ�. ����, �׷��� ���� ���ٸ� BRAK�� ����Ѵ�.

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

	// 1�� �ڸ����� 0������ ä����.

	bool Calculate(vector<int> tempCal)
	{
		if (tempCal[tempCal.size() - 1] >= 10)
			return false;

		for (int i = 0; i < tempCal.size()-1; ++i)
		{
			string num = to_string(tempCal[i]);
			while (num.size() != 1 || num != "0")
			{
				// 0�̳� 1 �̿ܰ� ������ ��
				if ((int)num.back() - 48 > 1)
					return false;
				// ���� ū �ڸ����� ���� �ش� ��ġ�� �Ű���.
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
	// ���ڸ��� 0�̳� 1�� �������� ���� ����.
	// divNum�� �� �ڸ� ���ڸ��� �ؾ���.
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