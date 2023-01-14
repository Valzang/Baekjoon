/*

문제
	작년에 이어 새로운 문자열 게임이 있다. 게임의 진행 방식은 아래와 같다.

	알파벳 소문자로 이루어진 문자열 W가 주어진다.
	양의 정수 K가 주어진다.
	어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
	어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.
	위와 같은 방식으로 게임을 T회 진행한다.

입력
	문자열 게임의 수 T가 주어진다. (1 ≤ T ≤ 100)
	다음 줄부터 2개의 줄 동안 문자열 W와 정수 K가 주어진다. (1 ≤ K ≤ |W| ≤ 10,000)

출력
	T개의 줄 동안 문자열 게임의 3번과 4번에서 구한 연속 문자열의 길이를 공백을 사이에 두고 출력한다.
	만약 만족하는 연속 문자열이 없을 시 -1을 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	string W = "";
	vector<vector<int>> alphabetCount;
	vector<pair<int,vector<int>>> alphabetOverK;
	vector<vector<int>> results;

	
	alphabetCount.resize(26);		
	
	int K = 0;
	int T;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> W >> K;

		// 알파벳 카운트 담아둘 벡터
		for (int i = 0; i < W.length(); ++i)
			alphabetCount[W[i] - 'a'].push_back(i);

		// 알파벳 카운트가 K 이상인 알파벳만 담아둘 벡터
		for (int i = 0; i < alphabetCount.size(); ++i)
		{
			if (alphabetCount[i].size() >= K)
				alphabetOverK.push_back(make_pair(i + 'a', alphabetCount[i]));
		}

		// 결과 담아둘 벡터
		results.resize(alphabetOverK.size());

	}


	return 0;
}