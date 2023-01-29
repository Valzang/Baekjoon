/*

문제
	크기가 N×M인 종이가 있고, 종이는 1×1크기의 칸으로 나누어져 있다. 
	이 종이의 각 칸 위에 1×1×1 크기의 정육면체를 놓아 3차원 도형을 만들었다.
	
	종이의 각 칸에 놓인 정육면체의 개수가 주어졌을 때, 이 도형의 겉넓이를 구하는 프로그램을 작성하시오.	
	
	위의 그림은 3×3 크기의 종이 위에 정육면체를 놓은 것이고, 겉넓이는 60이다.

입력
	첫째 줄에 종이의 크기 N, M이 주어진다. 둘째 줄부터 N개의 줄에는 종이의 각 칸에 놓인 정육면체의 수가 주어진다.

출력
	첫째 줄에 도형의 겉넓이를 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	vector<vector<int>> hexa;
	int result = 0;

	cin >> N >> M;
	hexa.resize(N);
	for (int i = 0; i < N; ++i)
	{
		hexa[i].resize(M);

		for (int j = 0; j < M; ++j)
		{
			cin >> hexa[i][j];


			// 위, 아래에서 본 넓이
			if (hexa[i][j] != 0)
				result += 2;

			if (j > 0 && hexa[i][j - 1] != hexa[i][j])
			{
				int diff = hexa[i][j] - hexa[i][j - 1];				
				result += (diff < 0 ? -diff : diff);				
			}
		
		}
		result += hexa[i][0] + hexa[i][M - 1];
	}

	// 전, 후에서 본 넓이
	for (int j = 0; j < M; ++j)
	{

		for (int i = 0; i < N; ++i)
		{
			if (i > 0 && hexa[i-1][j] != hexa[i][j])
			{
				int diff = hexa[i][j] - hexa[i-1][j];
				result += (diff < 0 ? -diff : diff);
			}

		}
		result += hexa[0][j] + hexa[N-1][j];
	}
	

	cout << result;

	return 0;

}
