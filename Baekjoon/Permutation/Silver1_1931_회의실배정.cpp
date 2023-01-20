/*

����
	�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�. 
	�� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, 
	�� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ȸ���� �ִ� ������ ã�ƺ���. 
	
	��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. 
	ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. 
	�� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.

�Է�
	ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����. 
	��° �ٺ��� N+1 �ٱ��� �� ȸ���� ������ �־����µ� 
	�̰��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. 

	���� �ð��� ������ �ð��� 231-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
	ù° �ٿ� �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ����Ѵ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.second == b.second ? a.first < b.first : a.second < b.second;
}

int main()
{
	int N;
	int maxResult = 1;
	vector<pair<int, int>> info;

	cin >> N;
	info.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> info[i].first >> info[i].second;

	sort(info.begin(), info.end(), compare);

	int time = info[1].second;
	for (int i = 2; i <= N; ++i)
	{
		if (info[i].first >= time)
		{
			++maxResult;
			time = info[i].second;
		}
	}


	cout << maxResult;

	return 0;
}