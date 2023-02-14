/*

����
	���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.
	
	���� ���, {10, 20, 30, 25, 20}�� {10, 20, 30, 40}, {50, 40, 25, 10} �� ������� ����������,
	{1, 2, 3, 2, 1, 2, 3, 2, 1}�� {10, 20, 30, 40, 20, 30} �� ������� ������ �ƴϴ�.
	
	���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� ���� A�� ũ�� N�� �־�����, ��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� N �� 1,000, 1 �� Ai �� 1,000)

���
	ù° �ٿ� ���� A�� �κ� ���� �߿��� ���� �� ������� ������ ���̸� ����Ѵ�.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N = 0;
vector<pair<int, pair<int, int>>> result;

bool compareDescend(pair<int, pair<int, int>> A, pair<int, pair<int,int>> B)
{
	return A.second.second > B.second.second;
}

bool compareAscend(pair<int, pair<int, int>> A, pair<int, pair<int, int>> B)
{
	return A.second.first < B.second.first;
}

int GetLeft(int index)
{
	if (index == 0)
		return 0;
	vector<pair<int,pair<int, int>>> copy(result.begin(), result.begin() + index);
	sort(copy.begin(), copy.end(), compareAscend);

	for (int i = copy.size() - 1; i >= 0; --i)
	{
		if (result[index].first > copy[i].first)
		{
			result[index].second.first = copy[i].second.first + 1;
			return result[index].second.first;
		}
	}
	return 0;
}

int GetRight(int index)
{
	if (index == N-1)
		return 0;
	vector<pair<int, pair<int, int>>> copy(result.begin() + index + 1, result.end());
	sort(copy.begin(), copy.end(), compareDescend);

	for (int i = 0; i < copy.size(); ++i)
	{
		if (result[index].first > copy[i].first)
		{
			result[index].second.second = copy[i].second.second + 1;
			return result[index].second.second;
		}
	}
	return 0;
}

int main()
{

	cin >> N;
	result.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> result[i].first;
		GetLeft(i);
	}

	int max = 0;
	for (int i = N-1; i >= 0; --i)
	{
		int bytonic = result[i].second.first + GetRight(i) + 1;
		if (max < bytonic)
			max = bytonic;
	}

	cout << max;

	return 0;
}