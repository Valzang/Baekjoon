/*

���� :
	N���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���. 
	�� ������ ������ ����ؼ�, �� ��ġ�� ���� K���� �ǵ��� �ϰ� �ʹ�. �� ����� ���� ���Ͻÿ�. 
	
	������ ������ �� ���� ����� �� �ִ�.
	����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է� :
	ù° �ٿ� N, K�� �־�����. (1 �� N �� 100, 1 �� K �� 10,000) 
	���� N���� �ٿ��� ������ ������ ��ġ�� �־�����. 
	������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�.

��� :
	ù° �ٿ� ����� ���� ����Ѵ�. ����� ���� 231���� �۴�.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	unsigned int resultCount;
	vector<int> coinValues;
	int* coinCounts;

	cin >> N >> K;

	coinCounts = new int[K+1];

	fill_n(coinCounts, K+1, 0);


	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		coinValues.push_back(temp);
	}

	coinCounts[0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (j >= coinValues[i])
				coinCounts[j] += coinCounts[j - coinValues[i]];
		}
	}

	cout << coinCounts[K];


	return 0;
}



