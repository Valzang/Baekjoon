/*
����
	������ ���� ���� �ڸ��� ���������� �̷�� ���� ���Ѵ�. 
	�̶�, ������ ���� ���Ƶ� ������������ ģ��.	

	���� ���, 2234�� 3678, 11119�� ������ ��������, 2232, 3676, 91111�� ������ ���� �ƴϴ�.	

	���� ���� N�� �־����� ��, ������ ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
	���� 0���� ������ �� �ִ�.

�Է�
	ù° �ٿ� N (1 �� N �� 1,000)�� �־�����.

���
	ù° �ٿ� ���̰� N�� ������ ���� ������ 10,007�� ���� �������� ����Ѵ�.

*/

#include <iostream>

using namespace std;

int results[1001][10];
int total[1001];

int main()
{
	int N;
	int divider = 10007;	

	for (int i = 0; i <= 9; ++i)
	{
		results[1][i] = 1;
		total[1] += 1;
		results[2][i] = 10 - i;
		total[2] += results[2][i];
	}

	cin >> N;

	for (int i = 3; i <= N; ++i)
	{
		results[i][0] = total[i - 1];
		total[i] = total[i - 1];
		for (int j = 1; j <= 9; ++j)
		{
			results[i][j] = (results[i][j-1] % divider - results[i - 1][j - 1] % divider + divider) % divider;
			total[i] = (total[i] + results[i][j]) % divider;
		}		
	}

	cout << total[N];
	return 0;
}