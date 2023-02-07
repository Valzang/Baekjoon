/*

����
	n���� ������ �̷���� ������ ������ �־�����. 
	�츮�� �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���Ϸ��� �Ѵ�. 
	��, ���� �� �� �̻� �����ؾ� �Ѵ�.	

	���� �� 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 �̶�� ������ �־����ٰ� ����. 
	���⼭ ������ 12+21�� 33�� ������ �ȴ�.

�Է�
	ù° �ٿ� ���� n(1 �� n �� 100,000)�� �־����� ��° �ٿ��� n���� ������ �̷���� ������ �־�����. 
	���� -1,000���� ũ�ų� ����, 1,000���� �۰ų� ���� �����̴�.

���
	ù° �ٿ� ���� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> arr;
	vector<int> result;
	int max = -100000000;

	cin >> N;
	arr.resize(N);
	result.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		result[i] = arr[i];
		if (i > 0 && result[i] < result[i] + result[i - 1])
			result[i] = result[i] + result[i - 1];
		if (max < result[i])
			max = result[i];
	}

	cout << max;

	return 0;
}