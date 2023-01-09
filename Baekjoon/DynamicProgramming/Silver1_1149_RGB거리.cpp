/*

문제
	RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
	집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다.

	각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

	- 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
	- N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
	- i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
입력
	첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다.
	둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
	집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
	첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
*/



#include <iostream>

using namespace std;

int R = 0;
int G = 1;
int B = 2;

int colorCost[1001][3];

int Min(int A, int B, int C = -1)
{
	if(C==-1)
		return A < B ? A : B;
	
	A = A < B ? A : B;
	return A < C ? A : C;
}

int main()
{
	int houseCount;

	cin >> houseCount;

	for (int i = 1; i <= houseCount; ++i)
	{
		cin >> colorCost[i][R] >> colorCost[i][G] >> colorCost[i][B];
		colorCost[i][R] += Min(colorCost[i - 1][G], colorCost[i - 1][B]);
		colorCost[i][G] += Min(colorCost[i - 1][B], colorCost[i - 1][R]);
		colorCost[i][B] += Min(colorCost[i - 1][R], colorCost[i - 1][G]);
	}

	cout << Min(colorCost[houseCount][R], colorCost[houseCount][G], colorCost[houseCount][B]);

	return 0;
}

/*


반례 1
10
711 572 325
209 187 673
512 930 898
759 85 260
136 226 532
201 3 959
132 607 359
601 775 848
462 776 920
74 807 671

답 3058

*/