/*

����
	RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.
	
	���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�. 
	������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.
	
	1�� ���� ���� 2��, N�� ���� ���� ���� �ʾƾ� �Ѵ�.
	N�� ���� ���� N-1��, 1�� ���� ���� ���� �ʾƾ� �Ѵ�.
	i(2 �� i �� N-1)�� ���� ���� i-1, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.

�Է�
	ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����. 
	��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����. 
	���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.

���
	ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int GetMin(int A, int B, int C = 10000001, int D = 10000001)
{
	A = A > C ? C : A;
	B = B > D ? D : B;

	return A > B ? B : A;
}

int main()
{
	int N;
	int result = 10000001;
	vector<vector<int>> cost;
	vector<vector<int>> tempResult;

	cin >> N;
	cost.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cost[i].resize(3);
		for (int j = 0; j < 3; ++j)
			cin >> cost[i][j];
	}

	for (int k = 0; k < 3; ++k)
	{
		tempResult = cost;
		for (int l = 0; l < 3; ++l)
		{
			if (k == l)
			{
				tempResult[1][l] = 10000001;
				continue;
			}
			tempResult[1][l] += tempResult[0][k];
		}

		for (int i = 2; i < N; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				int A = 0;
				int B = 0;
				switch (j)
				{
					case 0:
						A = 1, B = 2;
						break;
					case 1:
						A = 0, B = 2;
						break;
					case 2:
						A = 0, B = 1;
						break;
				}
				tempResult[i][j] += GetMin(tempResult[i-1][A], tempResult[i-1][B]);
			}
		}
		tempResult[N-1][k] = 10000001;
		result = GetMin(result, tempResult[N - 1][0], tempResult[N - 1][1], tempResult[N - 1][2]);		
	}

	cout << result;

	return 0;
}