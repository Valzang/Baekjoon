/*
����
	���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
	- X�� 3���� ������ ��������, 3���� ������.
	- X�� 2�� ������ ��������, 2�� ������.
	- 1�� ����.
	���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

�Է�
	ù° �ٿ� 1���� ũ�ų� ����, 10^6���� �۰ų� ���� ���� N�� �־�����.

���
	ù° �ٿ� ������ �ϴ� Ƚ���� �ּڰ��� ����Ѵ�.

*/

#include <iostream>

using namespace std;

int GetMin(int A, int B, int C)
{
	int min = A > B ? B : A;
	return min > C ? C : min;
}

int main()
{
	int N;
	int *min;

	cin >> N;
	min = new int[N+1];
	fill_n(min, N+1, 1000001);
	min[1] = 0;

	for (int i = 2; i <= N; ++i)
		min[i] = GetMin( i % 3 == 0 ? min[i/3] : min[i], i % 2 == 0 ? min[i / 2] : min[i], min[i-1]) + 1;

	cout << min[N];

	delete[] min;

	return 0;
}