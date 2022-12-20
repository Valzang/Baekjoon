#include <iostream>
#include <vector>

using namespace std;
int main()
{	
	int initInfectCount = 0;					// 1<= C <= 100	
	int increaseRatio = 0;					// 1<= R <= 100		
	unsigned long long spreadingTime = 0;	// 1<= T <= 10^13

	int divider = 1000000007;

	cout << "�ʱ� ������ : ";			cin >> initInfectCount;
	cout << "�ð��� ���� ��� : ";		cin >> increaseRatio;
	cout << "�������� �ð� : ";		cin >> spreadingTime;

	// unsigned long long int�� ������ 10^19�����̹Ƿ� �� ���� ������ 9 ������ ����.

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