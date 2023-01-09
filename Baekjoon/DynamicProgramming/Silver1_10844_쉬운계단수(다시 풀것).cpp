/*

����
	45656�̶� ���� ����.
	�� ���� ������ ��� �ڸ��� ���̰� 1�̴�. �̷� ���� ��� ����� �Ѵ�.
	N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���غ���. 0���� �����ϴ� ���� ��ܼ��� �ƴϴ�.

�Է�
	ù° �ٿ� N�� �־�����. N�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �ڿ����̴�.

���
	ù° �ٿ� ������ 1,000,000,000���� ���� �������� ����Ѵ�.

*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	unsigned int div = 1000000000;
	unsigned int result[101] = { 0, };
	int counts[101][10] = { 0, };
	
	cin >> N;

	counts[1][0] = 0;
	for (int j = 1; j < 10; ++j)
		counts[1][j] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (j == 0)
				counts[i][j] = counts[i - 1][j + 1] ;
			else if( j== 9)
				counts[i][j] = counts[i - 1][j - 1];
			else
				counts[i][j] = (counts[i - 1][j - 1] % div + counts[i - 1][j + 1] % div) % div;
		}
	}
	for (int i = 0; i <= 9; ++i)
		result[N] = (result[N] % div + counts[N][i]) % div;

	cout << result[N];

	return 0;
}

/*
����
https://ideone.com/n9K9id
*/