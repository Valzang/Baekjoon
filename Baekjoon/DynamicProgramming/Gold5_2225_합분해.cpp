/*
����
	0���� N������ ���� K���� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	������ ������ �ٲ� ���� �ٸ� ���� ����(1+2�� 2+1�� ���� �ٸ� ���). 
	���� �� ���� ���� ���� �� �� ���� �ִ�.

�Է�
	ù° �ٿ� �� ���� N(1 �� N �� 200), K(1 �� K �� 200)�� �־�����.

���
	ù° �ٿ� ���� 1,000,000,000���� ���� �������� ����Ѵ�.	
*/

#include <iostream>

using namespace std;

int main()
{
	int N, K;
	int **result;

	int divider = 1000000000;

	cin >> N >> K;
	result = new int* [N+1];
	for (int i = 0 ; i<=N; ++i)
		result[i] = new int[K+1];

	for (int i = 2 ; i<=K; ++i)
		result[1][i] = i;
	for (int i = 1; i <= N; ++i)
		result[i][1] = 1;

	for (int j = 2; j <= N; ++j)
	{
		for (int k = 2; k <= K; ++k)
			result[j][k] = (result[j][k-1] + result[j-1][k]) % divider;
	}

	cout << result[N][K];

	for (int i = 0 ; i<=N; ++i)
		delete[] result[i];

	delete[] result;

	return 0;
}