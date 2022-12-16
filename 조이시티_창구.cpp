#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*

창구 : 1~10개

손님 : vector<vector<int>> simulation;
	ex) [[0,3], [2,5], [4,3], [5,2]]
			3      7     
		=> 0초에 와서 상담 받는데 3초 걸림, 2초에 와서 상담받는데 5초 걸림.


	각 자 기다린 시간 총합 출력:
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
			// 창구 상담 종료 시간이 손님이 들어온 시간보다 빠를 때 ( 즉, 안 기다려도 될 때 )
			if (windows[k] <= simulation[j][0])
			{
				leastWaitTime = 0;
				windows[k] = simulation[j][0] + simulation[j][1];
				break;
			}
			// 들어온 손님이 기다려야하고, 그 중에서도 덜 기다려도 되는 창구 고르기
			else if (windows[k] - simulation[j][0] < leastWaitTime)
			{
				leastWaitTime = windows[k] - simulation[j][0];
				nextWindow = k;
			}
		}
		// 기다려야했을 때 , 해당 창구의 상담 종료시간 = 현재 손님의 상담 소요 시간 + 대기 시간
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