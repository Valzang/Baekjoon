/*
����
	������ ���� ���ӿ��� ȭ���� ������ ����(rupee)��. 
	�׷��� ��Ȥ '���� ����'�� �Ҹ��� ������ ���ǵ� �����ϴµ�, �̰� ȹ���ϸ� ������ ������ ���ǰ� �����ϰ� �ȴ�!

	������ ���� �ø����� ���ΰ�, ��ũ�� ���� ���Ϸ��Ǹ� ������ N x N ũ���� ������ ���� ���� ���� �ִ�. 
	[0][0]�� ĭ�̱⵵ �ϴ�. �� �̷� ���� ���Գİ� ���´ٸ� �ۿ��� ������� �ڲ� "������ ������ ������ ��� �ְ� ������?"��� ����ñ� �����̴�. 
	
	��ũ�� ��� ���� ���� ���ΰ��̰� ���ٴ� �׳� �����ִ� �����ε�, ���� Ÿ��Ʋ�� ���ٰ� �����ִٰ� �ڲ� ������� �̷��� �����ϴϱ� ���ź��� �ɸ� ���⿡ ���� ���̴�.

	�Ͽ�ư ����...�ƴ� ��ũ�� �� ������ �ݴ��� �ⱸ, ���� ������ �Ʒ� ĭ�� [N-1][N-1]���� �̵��ؾ� �Ѵ�. 
	������ �� ĭ���� ���Ϸ��ǰ� �ִµ�, �� ĭ�� ������ �ش� ���Ϸ����� ũ�⸸ŭ �������� �Ұ� �ȴ�. 
	
	��ũ�� �Ҵ� �ݾ��� �ּҷ� �Ͽ� ���� �ǳ������ �̵��ؾ� �ϸ�, �� ���� �����¿� ������ ������ 1ĭ�� �̵��� �� �ִ�.
	��ũ�� ���� ���ۿ� ���� �ּ� �ݾ��� ���ϱ�?

�Է�
	�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.
	�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�⸦ ��Ÿ���� ���� N (2 �� N �� 125)�� �־�����.  
	
	N = 0�� �Է��� �־����� ��ü �Է��� ����ȴ�.
	�̾ N���� �ٿ� ���� ������ �� ĭ�� �ִ� ���Ϸ����� ũ�Ⱑ �������� ���еǾ� ���ʴ�� �־�����. 
	���� ������ ũ�Ⱑ k�� �� ĭ�� ������ k���Ǹ� �Ҵ´ٴ� ���̴�. 
	
	���⼭ �־����� ��� ������ 0 �̻� 9 ������ �� �ڸ� ����.

���
	�� �׽�Ʈ ���̽����� �� �ٿ� ���� ������ ���Ŀ� ���缭 ����Ѵ�. ������ ���� ����� �����Ͻÿ�.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int cave[125][125];
int mid[125][125];
bool check[125][125];

struct Vector2
{
	int row = 0, col = 0, val = 0;
	Vector2() { row = 0, col = 0, val = 0; }
	Vector2(int r, int c, int v) { row = r, col = c, val = v; }
	const Vector2 operator=(const Vector2 v)
	{
		row = v.row;
		col = v.col;
		val = v.val;
	}
	const bool operator>(const Vector2 v)
	{
		return val > v.val;
	}
};

priority_queue<Vector2> pq;

void GetResult(int i, int j, int N)
{	
	if (check[i][j])
		return;

	Vector2 vec(i,j,mid[i][j]);
	pq.push(vec);

	check[i][j] = true;

	do 
	{
		Vector2 curVec = pq.top();
		pq.pop();
		if (check[i][j])
			continue;

		check[i][j] = true;

		if (curVec.row >= 1)
		{
			int temp = mid[curVec.row - 1][curVec.col] > mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] 
				? mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] : mid[curVec.row - 1][curVec.col];
			curVec = Vector2(curVec.row - 1, j, temp);
			pq.push(curVec);
		}
		if (curVec.row < N - 1)
		{
			int temp = mid[curVec.row + 1][curVec.col] > mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] 
				? mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] : mid[curVec.row + 1][curVec.col];
			curVec = Vector2(i + 1, j, temp);
			pq.push(curVec);
		}
		if (j >= 1)
		{
			int temp = mid[curVec.row][curVec.col - 1] > mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] 
				? mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] : mid[curVec.row][curVec.col - 1];
			curVec = Vector2(i, j - 1, temp);
			pq.push(curVec);
		}
		if (j < N - 1)
		{
			int temp = mid[curVec.row][curVec.col + 1] > mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] 
				? mid[curVec.row][curVec.col] + cave[curVec.row][curVec.col] : mid[curVec.row][curVec.col + 1];
			curVec = Vector2(i, j + 1, temp);
			pq.push(curVec);
		}
	} while (!pq.empty());
}

int main()
{
	int N;
	vector<int> results;
	cin >> N;

	while (N != 0)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> cave[i][j];
				mid[i][j] = INT_MAX;				
			}
		}		
		mid[0][0] = cave[0][0];
		GetResult(0, 0, N);
		results.push_back(mid[N - 1][N - 1]);

		cin >> N;
	}


	return 0;
}