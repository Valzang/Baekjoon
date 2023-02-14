/*

����
	���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 
	���� �� �����ϴ� �κ� ������ A = {30, 20, 10}  �̰�, ���̴� 3�̴�.

�Է�
	ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
	��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
	ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> A, pair<int, int> B)
{
	return A.second > B.second;
}

int main()
{
	int N = 0;
	vector<int> A;
	vector<pair<int,int>> result;
	cin >> N;

	A.resize(N);
	result.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		result[i] = make_pair(A[i], 1);
	}

	int max = 1;
	for (int i = N - 2; i >= 0; --i)
	{
		sort(result.begin() + i + 1, result.end(), compare);
		for (int j = i + 1; j < N; ++j)
		{
			if (A[i] > result[j].first)
			{
				result[i].second += result[j].second;
				break;
			}
		}
		if (max < result[i].second)
			max = result[i].second;
	}

	cout << max;

	return 0;
}