#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*

â�� : 1~10��

�մ� : vector<vector<int>> simulation;
	ex) [[0,3], [2,5], [4,3], [5,2]]
			3      7     
		=> 0�ʿ� �ͼ� ��� �޴µ� 3�� �ɸ�, 2�ʿ� �ͼ� ���޴µ� 5�� �ɸ�.


	�� �� ��ٸ� �ð� ���� ���:
	*/

int solution(int N, vector<vector<int>> simulation)
{
	int totalTime = 0;
	vector<int> windows(N,0);
	for (int i = 0; i < N; ++i)
	{		
		windows[i] = simulation[i][0] + simulation[i][1];
	}

	for (int j = N; j < simulation.size(); ++j)
	{
		int leastWaitTime = numeric_limits<int>::max();
		int nextWindow = 0;
		for (int k = 0; k < windows.size(); ++k)
		{
			// â�� ��� ���� �ð��� �մ��� ���� �ð����� ���� �� ( ��, �� ��ٷ��� �� �� )
			if (windows[k] <= simulation[j][0])
			{
				leastWaitTime = 0;
				windows[k] = simulation[j][0] + simulation[j][1];
				break;
			}
			// ���� �մ��� ��ٷ����ϰ�, �� �߿����� �� ��ٷ��� �Ǵ� â�� ����
			else if (windows[k] - simulation[j][0] < leastWaitTime)
			{
				leastWaitTime = windows[k] - simulation[j][0];
				nextWindow = k;
			}
		}
		// ��ٷ������� �� , �ش� â���� ��� ����ð� = ���� �մ��� ��� �ҿ� �ð� + ��� �ð�
		if (leastWaitTime != 0)
			windows[nextWindow] = simulation[j][0] + simulation[j][1] + leastWaitTime;
		totalTime += leastWaitTime;
	}

	return totalTime;
}


int main()
{
	return 0;
}