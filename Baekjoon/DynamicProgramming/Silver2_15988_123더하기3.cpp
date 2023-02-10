/*

문제
	정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
	
	- 1+1+1+1
	- 1+1+2
	- 1+2+1
	- 2+1+1
	- 2+2
	- 1+3
	- 3+1

	정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
	첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 1,000,000보다 작거나 같다.

출력
	각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.

*/


#include <iostream>
#include <vector>

using namespace std;
vector<unsigned long long> result;
unsigned long long divider = 1000000009;

unsigned long long GetResult(int index)
{	
	if (result[index] == 0)
		result[index] = GetResult(index - 1) + GetResult(index - 2) + GetResult(index - 3);
	
	return result[index] % divider;
}

int main()
{
	int T = 0;
	vector<unsigned int> answer;
	result.resize(1000001);

	cin >> T;
	answer.resize(T);
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	for (int i = 0; i < T; ++i)
	{		
		int N = 0;
		cin >> N;
		answer[i] = (int)GetResult(N);
	}

	for (int i = 0; i < T; ++i)
		cout << answer[i] << '\n';

	return 0;
}