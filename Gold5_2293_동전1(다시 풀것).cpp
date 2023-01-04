/*

문제 :
	N가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 
	이 동전을 적당히 사용해서, 그 가치의 합이 K원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 
	
	각각의 동전은 몇 개라도 사용할 수 있다.
	사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력 :
	첫째 줄에 N, K가 주어진다. (1 ≤ N ≤ 100, 1 ≤ K ≤ 10,000) 
	다음 N개의 줄에는 각각의 동전의 가치가 주어진다. 
	동전의 가치는 100,000보다 작거나 같은 자연수이다.

출력 :
	첫째 줄에 경우의 수를 출력한다. 경우의 수는 231보다 작다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	unsigned int resultCount;
	vector<int> coinValues;
	int* coinCounts;

	cin >> N >> K;

	coinCounts = new int[K+1];

	fill_n(coinCounts, K+1, 0);


	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		coinValues.push_back(temp);
	}

	coinCounts[0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			if (j >= coinValues[i])
				coinCounts[j] += coinCounts[j - coinValues[i]];
		}
	}

	cout << coinCounts[K];


	return 0;
}



