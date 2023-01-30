/*
����
	���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 3������ �ִ�. ���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�. ��, ���� ���� �� �� �̻� �����ؼ� ����ϸ� �� �ȴ�.

		1+2+1
		1+3
		3+1

	���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����. n�� ����̸� 100,000���� �۰ų� ����.

���
	�� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� 1,000,000,009�� ���� �������� ����Ѵ�.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T = 0;
	int divider = 1000000009;
	int max = 0;
	vector<vector<unsigned long long>> answer;
	vector<int> number;

	cin >> T;
	number.resize(T);
	for (int i = 0; i < T; ++i)
	{
		cin >> number[i];
		if (max < number[i])
			max = number[i];
	}
	answer.resize(max+1);

	answer[0].resize(4);

	for (int i = 0; i <= 3; ++i)
		answer[0][i] = 0;
	
	for (int i = 1; i <= 3; ++i)
	{
		answer[i].resize(4);
		answer[i][0] = 1;
		for (int j = 1; j <= 3; ++j)
			answer[i][j] = i == j ? 1 : 0;
	}
	answer[3][1] = 1;
	answer[3][2] = 1;
	answer[3][0] = 3;

	for (int i = 4; i <= max; ++i)
	{
		answer[i].resize(4);		
		answer[i][1] = (answer[i - 1][2] + answer[i - 1][3]) % divider;
		answer[i][2] = (answer[i - 2][1] + answer[i - 2][3]) % divider;
		answer[i][3] = (answer[i - 3][1] + answer[i - 3][2]) % divider;
		answer[i][0] = (answer[i][1] + answer[i][2] + answer[i][3]) % divider;
	}

	for (int i = 0; i < T; ++i)
		cout << answer[number[i]][0] << '\n';

	return 0;
}