/*

문제
            7
          3   8
        8   1   0
      2   7   4   4
    4   5   2   6   5
    위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

    맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
    이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
    
    아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
    
    삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
    첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
    첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> triangles;
vector<vector<int>> results;

int main()
{
    int n = 0;

    cin >> n;
    triangles.resize(n);

    for (int i = 0; i < n; ++i)
    {
        triangles[i].resize((size_t)(i+1));
        for (int j = 0; j <= i; ++j)
            cin >> triangles[i][j];
    }

    results = triangles;

    for (int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            int value1 = triangles[i + 1][j] + results[i][j];
            int value2 = triangles[i + 1][j+1] + results[i][j];
            if (results[i + 1][j] < value1)
                results[i + 1][j] = value1;
            if (results[i + 1][j + 1] < value2)
                results[i + 1][j + 1] = value2;
        }
    }
    sort(results[n - 1].begin(), results[n - 1].end());

    cout << results[n - 1][n - 1];

	return 0;
}