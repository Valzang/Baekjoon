/*

����
	n���� ������ �̷���� ������ ������ �־�����. 
	�츮�� �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�. 
	
	��, ���� �� �� �̻� �����ؾ� �Ѵ�. ��, �������� ���� �ϳ� ������ �� �ִ�. (�������� �ʾƵ� �ȴ�)
	
	���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����. 
	���⼭ ���� �������� �ʾ��� ���� ������ 12+21�� 33�� ������ �ȴ�.
	
	����, -35�� �����Ѵٸ�, ������ 10, -4, 3, 1, 5, 6, 12, 21, -1�� �ǰ�, 
	���⼭ ������ 10-4+3+1+5+6+12+21�� 54�� �ȴ�.

�Է�
	ù° �ٿ� ���� n(1 �� n �� 100,000)�� �־����� ��° �ٿ��� n���� ������ �̷���� ������ �־�����. 
	���� -1,000���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

���
	ù° �ٿ� ���� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<pair<int,int>> answer;

int main()
{
	int n = 0;
	cin >> n;
	arr.resize(n);
	answer.resize(n);

	int max = -1000;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (i > 0)
		{
			int prevValue1 = answer[i-1].first;
			int prevValue2 = answer[i-1].second;

			answer[i].first = prevValue1 > 0 ? arr[i] + prevValue1 : arr[i];
			answer[i].second = prevValue1 > prevValue2 + arr[i] ? prevValue1 : prevValue2 + arr[i];
		}
		else
		{
			answer[i].first = arr[i];
			answer[i].second = arr[i];
		}
		int tempMax = answer[i].first > answer[i].second ? answer[i].first : answer[i].second;
		if (max < tempMax)
			max = tempMax;
	}


	cout << max;

	return 0;
}