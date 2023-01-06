/*

����
	n���� ������ ������ �ִ�. �� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. 
	�׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�. ������ ������ �� ���� ����� �� �ִ�.
	
	����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
	ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) 
	���� n���� �ٿ��� ������ ������ ��ġ�� �־�����. ������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�. 
	��ġ�� ���� ������ ���� �� �־��� ���� �ִ�.

���
	ù° �ٿ� ����� ������ �ּ� ������ ����Ѵ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int Min(int A, int B)
{
	return A > B ? B : A;
}

int main()
{
	int N, K;
	int* coinCounts = new int[10001];
	fill_n(coinCounts, 10001, 10001);

	coinCounts[0] = 0;

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		int temp;
		cin >> temp;
		for (int j = temp; j <= K; ++j)
			coinCounts[j] = Min(coinCounts[j] , coinCounts[j - temp] + 1);
	}

	if(coinCounts[K] == 10001)
		coinCounts[K] = -1;

	cout << coinCounts[K];

	delete[] coinCounts;

	return 0;
}