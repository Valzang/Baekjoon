/*

����
	���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.	
	���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ���,
	���� ���� ū ���� �κ� ������ A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �̰�, ���� 113�̴�.

�Է�
	ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
	
	��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
	ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�.

*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int answer = 0;
	vector<int> result;
	vector<int> progression;

	cin >> N;
	progression.resize(N + 1);
	result.resize(N + 1);

	for (int i = 1; i <= N; ++i)
		cin >> progression[i];

	for (int i = N; i >= 0; --i)
	{
		int curNum = progression[i];
		int startNum = curNum;
		result[i] = curNum;
		for (int j = i+1; j <= N; ++j)
		{			
			if (progression[j] > startNum && (progression[j] <= curNum || startNum == curNum))
			{
				curNum = progression[j];
				int sum = startNum + result[j];
				result[i] = result[i] > sum ? result[i] : sum;
			}
		}
		if (answer < result[i])
			answer = result[i];
	}

	cout << answer;


	return 0;
}