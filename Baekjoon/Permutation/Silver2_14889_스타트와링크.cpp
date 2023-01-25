#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int diff = 1000000;
vector<vector<int>> S;

void DFS(vector<bool> check, vector<int> start, vector<int> link)
{
	int max = N / 2;
	if (start.size() == max)
	{
		for (int i = 0; i < N; ++i)
		{
			if (check[i])
				link.push_back(i);
		}
		int startCount = 0;
		int linkCount = 0;
		for (int i = 0; i < max; ++i)
		{
			for (int j = 0; j < max; ++j)
			{
				if (i == j) continue;
				startCount += S[start[i]][start[j]];
				linkCount += S[link[i]][link[j]];
			}
		}
		int temp = startCount - linkCount;
		if (temp < 0)
			temp = -temp;		
		if (diff > temp)
			diff = temp;
		return;
	}

	int last = 0;
	if(start.size() != 0 )
		last = start.back();

	for (int i = last; i < N; ++i)
	{
		if (!check[i])
			continue;
		start.push_back(i);
		check[i] = false;
		DFS(check, start, link);
		check[i] = true;
		start.pop_back();
	}
}

int main()
{
	vector<bool> check;
	vector<int> start;
	vector<int> link;

	cin >> N;
	S.resize(N);
	check.resize(N);

	for (int i = 0; i < N; ++i)
	{
		check[i] = true;
		S[i].resize(N);
		for (int j = 0; j < N; ++j)
			cin >> S[i][j];
	}

	DFS(check, start, link);

	cout << diff;

	return 0;
}