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
	// ���ڸ��� 0�̳� 1�� �������� ���� ����.
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