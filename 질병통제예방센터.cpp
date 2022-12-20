#include <iostream>
#include <vector>

using namespace std;
int main()
{	
	int initInfectCount = 0;					// 1<= C <= 100	
	int increaseRatio = 0;					// 1<= R <= 100		
	unsigned long long spreadingTime = 0;	// 1<= T <= 10^13

	int divider = 1000000007;

	cout << "초기 감염자 : ";			cin >> initInfectCount;
	cout << "시간당 증가 배수 : ";		cin >> increaseRatio;
	cout << "퍼져나간 시간 : ";		cin >> spreadingTime;

	// unsigned long long int의 범위가 10^19까지이므로 그 절반 정도인 9 단위로 끊기.

	unsigned long long int splitTimes		= spreadingTime / 9;
	unsigned long long int remainder		= (int)(spreadingTime % 9);
	unsigned long long int result			= 1;
	for (int i = 0; i < splitTimes; ++i)
	{
		result *= ((unsigned long long int)pow(increaseRatio, 9) % divider);
		result %= divider;
	}
	result *= ((unsigned long long int)pow(increaseRatio, remainder) % divider);
	result %= divider;

	//

	result = (initInfectCount * result) % divider;

	cout << result << '\n';


	return 0;
}