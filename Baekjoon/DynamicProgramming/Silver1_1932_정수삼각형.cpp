/*

����
            7
          3   8
        8   1   0
      2   7   4   4
    4   5   2   6   5
    �� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.

    �� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��, 
    �������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�. 
    
    �Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.
    
    �ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.

�Է�
    ù° �ٿ� �ﰢ���� ũ�� n(1 �� n �� 500)�� �־�����, ��° �ٺ��� n+1��° �ٱ��� ���� �ﰢ���� �־�����.

���
    ù° �ٿ� ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ���� ����Ѵ�.

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