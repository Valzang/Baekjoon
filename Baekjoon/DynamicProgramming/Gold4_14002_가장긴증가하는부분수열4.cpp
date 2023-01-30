/*

����
	���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ {10, 20, 30, 50} �̰�, ���̴� 4�̴�.

�Է�
	ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.	
	��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
	ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.	
	��° �ٿ��� ���� �� �����ϴ� �κ� ������ ����Ѵ�. �׷��� ������ ���������� ��� �ƹ��ų� ����Ѵ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(vector<int> a, vector<int> b)
{
	return (int)a.size() > (int)b.size();
}

int main()
{
	int N = 0;
	vector<int> numbers;
	vector<vector<int>> answer;

	cin >> N;
	numbers.resize(N);
	answer.resize(N);

	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	for (int i = N - 1; i >= 0; --i)
	{
		int closeIndex = i;
		for (int j = i+1; j < N; ++j)
		{
			if (numbers[i] < numbers[j] && (int)answer[closeIndex].size() < (int)answer[j].size())
				closeIndex = j;
		}
		answer[i] = answer[closeIndex];
		answer[i].insert(answer[i].begin(), numbers[i]);
	}

	sort(answer.begin(), answer.end(), compare);

	cout << (int)answer[0].size() << '\n';
	for (int i = 0; i < (int)answer[0].size(); ++i)
		cout << answer[0][i] << " ";

	return 0;
}