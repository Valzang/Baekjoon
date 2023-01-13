/*

����
	3��N ũ���� ���� 2��1, 1��2 ũ���� Ÿ�Ϸ� ä��� ����� ���� ���غ���.

�Է�
	ù° �ٿ� N(1 �� N �� 30)�� �־�����.

���
	ù° �ٿ� ����� ���� ����Ѵ�.

*/


#include <iostream>

using namespace std;

int main()
{
	int N;
	unsigned long long results[31] = { 0, };

	cin >> N;

	results[0] = 1;
	results[1] = 0;
	results[2] = 3;

	for (int i = 4; i <= N; i+=2)
		results[i] = results[i - 2] * 4 - results[i-4];

	cout << results[N];
	


	return 0;
}