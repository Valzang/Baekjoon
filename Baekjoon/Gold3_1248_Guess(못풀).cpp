/*
문제
	연속된 정수가 주어지고 (a1, a2, ..., an) 이걸 부호 행렬 S로 사용한다.
	1<= i <= j <= n 이며
		ai + … + aj > 0 인 경우 Sij= "+"
		ai + … + aj < 0 인 경우 Sij= "-"
		그 외는 Sij = 0

	예를 들어, (a1, a2, a3, a4) = ( -1, 5, -4, 2), 인 경우 부호 행렬 S는 다음과 같은 4*4 행렬이 된다.

		1	2	3	4
	1	-	+	0	+
	2	 	+	+	+
	3	 	 	-	-
	4	 	 	 	+

	연속된 정수로 부호 행렬이 만들어질 수 있다면 그 행렬은 유효하다고 할 수 있으며 부호 행렬을 연산하기 쉽다.

	하지만 이 문제는 반대로, 부호 행렬이 주어지고 그 행렬을 만들 수 있는 연속된 정수를 찾는 것이다.
	같은 부호 행렬로 2개 이상의 연속된 정수들이 만들어질 수 있다.

	예를 들어 (-2, 5, -3, 1)과 (-1, 5, -4,2) 는 같은 부호 행렬을 만든다.

	주어진 부호 행렬을 만들어낼 수 있는 연속된 정수를 찾아라.
	이 때 모든 정수는 -10 이상, 10 이하 이다.

입력
	첫 째 줄엔 연속된 정수의 길이인 n(1<=n<=10) 을 입력 받고
	둘 째 줄엔 n(n+1)/2 개의 문자를 입력 받는다. 각 문자는 연속된 정수에 대응되는 문자들이다.

출력
	연속된 정수 한 줄을 출력한다.

	만약 연속된 정수가 2개 이상인 경우, 아무거나 출력해도 된다.
	단, 모든 정수는 -10 이상 10 이하이다.
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> signVec;
vector<int> iVec;

bool Check(int idx)
{
	int sum = 0;
	for (int i = idx; i >= 0; --i)
	{
		sum += iVec[i];
		char curSign = sum == 0 ? '0' : sum > 0 ? '+' : '-';
		if (signVec[i][idx] != curSign)
			return false;
	}
	return true;
}

void GetAnswer(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < n; ++i)
			cout << iVec[i] << " ";
		exit(0);
	}

	int start, end;
	if (signVec[cnt][cnt] == '-')
		start = -10, end = -1;
	else if (signVec[cnt][cnt] == '+')
		start = 1, end = 10;
	else
		start = 0, end = 0;

	for (int i = start; i <= end; ++i)
	{
		iVec[cnt] = i;
		if (Check(cnt))
			GetAnswer(cnt + 1);
	}
}

int main()
{
	cin >> n;
	iVec.resize(n);
	signVec.resize(n);

	for (int i = 0; i < n; ++i)
	{
		signVec[i].resize(n);
		for (int j = i; j < n; ++j)
			cin >> signVec[i][j];
	}

	GetAnswer(0);


	return 0;
}