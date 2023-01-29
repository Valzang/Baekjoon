/*

문제
	각각의 카드에는 등급을 나타내는 색이 칠해져 있고, 다음과 같이 8가지가 있다.
	
	전설 / 레드 / 오렌지 / 퍼플 / 블루 / 청록 / 그린 / 그레이

	카드는 카드팩의 형태로만 구매할 수 있고, 
	카드팩의 종류는 카드 1개가 포함된 카드팩, 카드 2개가 포함된 카드팩, ... 카드 N개가 포함된 카드팩과 같이 총 N가지가 존재한다.
	
	돈을 최소로 지불해서 카드 N개를 구매하려고 한다. 
	
	카드가 i개 포함된 카드팩의 가격은 Pi원이다.
	
	예를 들어, 카드팩이 총 4가지 종류가 있고, P1 = 1, P2 = 5, P3 = 6, P4 = 7인 경우에 
	민규가 카드 4개를 갖기 위해 지불해야 하는 금액의 최솟값은 4원이다. 
	
	1개 들어있는 카드팩을 4번 사면 된다.
	
	P1 = 5, P2 = 2, P3 = 8, P4 = 10인 경우에는 카드가 2개 들어있는 카드팩을 2번 사면 4원이고, 
	이 경우가 민규가 지불해야 하는 금액의 최솟값이다.
	
	카드 팩의 가격이 주어졌을 때, 
	N개의 카드를 구매하기 위해 민규가 지불해야 하는 금액의 최솟값을 구하는 프로그램을 작성하시오. 
	
	N개보다 많은 개수의 카드를 산 다음, 나머지 카드를 버려서 N개를 만드는 것은 불가능하다. 
	
	즉, 구매한 카드팩에 포함되어 있는 카드 개수의 합은 N과 같아야 한다.

입력
	첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
	
	둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)

출력
	첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최솟값을 출력한다.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> price;
	vector<int> minPrice;

	cin >> N;
	price.resize(N+1);
	minPrice.resize(N+1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> price[i];
		minPrice[i] = price[i];

		int evenOdd = i % 2;

		for (int j = i-1; j >= i / 2 + i%2; --j)
		{
			int curVal = minPrice[j] + minPrice[i - j];
			if (minPrice[i] > curVal)
				minPrice[i] = curVal;			
		}
	}

	cout << minPrice[N];

	return 0;
}