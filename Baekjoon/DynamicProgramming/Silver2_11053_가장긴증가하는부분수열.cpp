/*

����
	���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ���
	���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.

�Է�
	ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
	��° �ٿ��� ���� A�� �̷�� �ִ� A[i]�� �־�����. (1 �� Ai �� 1,000)

���
	ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.

*/


#include <iostream>

using namespace std;

int main()
{
	int N;
	int A[1001] = { 0, };
	int results[1001] = { 0, };
	int max = 0;

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> A[i];

	results[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		int maxIndex = i - 1;
		for (int j = i - 1; j >= 1; --j)
		{
			if (A[j] < A[i])
				maxIndex = A[maxIndex] < A[j] ? j : maxIndex;
		}
		results[i] = results[maxIndex] + 1;
		max = max < results[i] ? results[i] : max;
	}

	cout << max;

	return 0;
}