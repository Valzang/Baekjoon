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

	cin >> N;
	result[1] = 9;

	for (int i = 2; i <= N; ++i)
	{
		result[i] = ((result[i - 1] * 2) % div - (i - 1) % div) % div;
	}

	cout << result[N];

	return 0;
}

/*
����
https://ideone.com/n9K9id
*/