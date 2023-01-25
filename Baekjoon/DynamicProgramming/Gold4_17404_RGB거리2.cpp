/*

문제
	RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
	
	집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 
	각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
	
	1번 집의 색은 2번, N번 집의 색과 같지 않아야 한다.
	N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야 한다.
	i(2 ≤ i ≤ N-1)번 집의 색은 i-1, i+1번 집의 색과 같지 않아야 한다.

입력
	첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 
	둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 
	집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
	첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

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