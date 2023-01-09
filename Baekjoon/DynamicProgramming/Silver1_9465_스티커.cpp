#include <iostream>
#include <vector>

using namespace std;

int GetMax(int A, int B, int C = 0)
{
	A = A > B ? A : B;
	return A > C ? A : C;
}

int main()
{
	int T, n;
	vector<int> results;

	cin >> T;

	for (int k = 0; k < T; ++k)
	{
		cin >> n;
		int** points = new int* [2];
		int** totalPoints = new int* [2];
		for (int i = 0; i < 2; ++i)
		{
			points[i] = new int[n];
			totalPoints[i] = new int[n];
		}

		int temp = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			points[0][i] = temp;
			totalPoints[0][i] = temp;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> temp;
			points[1][i] = temp;
			totalPoints[1][i] = temp;
		}		
		if (n >= 2)
		{
			totalPoints[0][1] += totalPoints[1][0];
			totalPoints[1][1] += totalPoints[0][0];
		}	
		
		for (int i = 2; i < n; ++i)
		{
			totalPoints[0][i] += GetMax(totalPoints[1][i - 1], totalPoints[0][i - 2], totalPoints[1][i - 2]);
			totalPoints[1][i] += GetMax(totalPoints[0][i - 1], totalPoints[0][i - 2], totalPoints[1][i - 2]);
		}
		results.push_back(GetMax(totalPoints[0][n - 1], totalPoints[1][n - 1]));

		for (int i = 0; i < 2; ++i)
		{
			delete[] points[i];
			delete[] totalPoints[i];
		}
		delete[] points;
		delete[] totalPoints;		
	}

	for (int i = 0; i < results.size(); ++i)
		cout << results[i] << '\n';


	return 0;
}