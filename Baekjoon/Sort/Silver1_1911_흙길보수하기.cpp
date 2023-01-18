/*

����
	������ �ܿ� ķ�� ��ҿ��� ���� �������� �̾�����, 
	������ �� ��б� ���� ���찡 ������ N (1 <= N <= 10,000) ���� �������̰� �����. 
	
	�����п��� �������̸� ���� �� �ִ� ���� L (L�� ���� ����) ¥�� �κ������� ����� ������ �־, 
	�̵�� �ٸ��� ����� �������̵��� ��� �������� �Ѵ�. 
	
	�������̵��� ��ġ�� ũ�⿡ ���� ������ �־��� ��, 
	��� �������̵��� ���� ���� �ʿ��� �κ������� �ּ� ������ ���Ͽ���.

�Է�
	ù° �ٿ� N�� L�� ���´�.
	��° �ٺ��� N+1��° �ٱ��� �� N���� �ٿ� ������ �����̵��� ������ �־�����. 

	�������� ������ �������� ���� ��ġ�� �� ��ġ�� �̷������. 
	�� ��ġ�� 0�̻� 1,000,000,000������ �����̴�.

���
	ù° �ٿ� ��� �������̵��� ���� ���� �ʿ��� �κ������� �ּ� ������ ����Ѵ�.

��Ʈ
	111222..333444555.... // ���� 3�� �κ���
	.111222.333444555.... // ���� 3�� �κ���
	.MMMMM..MMMM.MMMM.... // ������
	012345678901234567890 // ��ǥ

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}


int main()
{
	int N, L;
	int result = 0;
	int count = 0;
	vector<pair<int, int>> puddles;

	cin >> N >> L;
	puddles.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> puddles[i].first >> puddles[i].second;
		--puddles[i].second;
	}

	sort(puddles.begin(), puddles.end(), compare);

	
	for (int i = puddles[0].first; i <= puddles.back().second;)
	{
		if (i >= puddles[count].first && i <= puddles[count].second)
		{
			++result;
			i += L;
		}
		else
			i = i > puddles[++count].first ? i : puddles[count].first;
	}

	cout << result;

	return 0;
}