/*

����
	���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 7������ �ִ�. ���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�.
	
	- 1+1+1+1
	- 1+1+2
	- 1+2+1
	- 2+1+1
	- 2+2
	- 1+3
	- 3+1

	���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����. n�� ����̸� 1,000,000���� �۰ų� ����.

���
	�� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� 1,000,000,009�� ���� �������� ����Ѵ�.

*/


#include <iostream>
#include <vector>

using namespace std;
vector<unsigned long long> result;
unsigned long long divider = 1000000009;

unsigned long long GetResult(int index)
{	
	if (result[index] == 0)
		result[index] = GetResult(index - 1) + GetResult(index - 2) + GetResult(index - 3);
	
	return result[index] % divider;
}

int main()
{
	int T = 0;
	vector<unsigned int> answer;
	result.resize(1000001);

	cin >> T;
	answer.resize(T);
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	for (int i = 0; i < T; ++i)
	{		
		int N = 0;
		cin >> N;
		answer[i] = (int)GetResult(N);
	}

	for (int i = 0; i < T; ++i)
		cout << answer[i] << '\n';

	return 0;
}