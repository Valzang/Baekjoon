#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*

������ ���� ������� ������ ���� ���� �����Ѵ�.

	- 0�� 1�θ� �̷���� �־�� �Ѵ�.
	- 1�� ��� �ϳ� �־�� �Ѵ�.
	- ���� ���̰� 100 �����̴�.
	- ���� 0���� �������� �ʴ´�.

���� ���, 101�� ������� �����ϴ� ���̴�.

- ù° �ٿ� �׽�Ʈ ���̽��� ���� T(T < 10)�� �־�����.
- ��° �ٺ��� T���� �ٿ��� �ڿ��� N�� �� �ٿ� �ϳ��� �־�����. N�� 20,000���� �۰ų� ���� �ڿ����̴�.

- ������ �׽�Ʈ ���̽����� N�� ����̸鼭, ������� �����ϴ� ���� �ƹ��ų� ����Ѵ�.
	����, �׷��� ���� ���ٸ� BRAK�� ����Ѵ�.

*/

// string�� ���� Ű�������鼭 �߰��� N���� ������������ ���. string�� ũ�Ⱑ 100�� �ʰ��ϸ� BRAK ���
// (A+B)%C = ((A%C) + (B%C)) %C
// (A*B)%C = ((A%C) * (B%C)) %C
// (A*A)%C = ((A%C) * (A%C)) %C
//	=> (10^99)%C = ((10^9 % C)^10)%C
// ex) 123456 % N =>
//		(1* 10^5 + 2*10^4 + 3*10^3 + 4*10^2 + 5*10^1 + 6*10^0) % N
//		=> ((1* 10^5 % N) + (2*10^4 % N ) + ( 3*10^3 % N ) + (4*10^2 % N ) + (5*10^1 %N ) + (6*10^0 % N )) %N

// int max => 2,147,483,647		�� 10�ڸ� ( 10^9)
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
	// N�� �ڸ����� �����ϰ� �����ֱ�
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