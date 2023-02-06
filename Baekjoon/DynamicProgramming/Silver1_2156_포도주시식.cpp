/*

����
	ȿ�ִ� ������ �ý�ȸ�� ����. �� ���� ������, ���̺� ���� �پ��� �����ְ� ����ִ� ������ ���� �Ϸķ� ���� �־���. 
	ȿ�ִ� ������ �ý��� �Ϸ��� �ϴµ�, ���⿡�� ������ ���� �� ���� ��Ģ�� �ִ�.
	
	������ ���� �����ϸ� �� �ܿ� ����ִ� �����ִ� ��� ���ž� �ϰ�, ���� �Ŀ��� ���� ��ġ�� �ٽ� ���ƾ� �Ѵ�.
	�������� ���� �ִ� 3���� ��� ���� ���� ����.
	ȿ�ִ� �� �� �ִ� ��� ���� ���� �����ָ� ������ ���ؼ� � ������ ���� �����ؾ� ���� ����ϰ� �ִ�. 
	
	1���� n������ ��ȣ�� �پ� �ִ� n���� ������ ���� ������� ���̺� ���� ���� �ְ�, 
	�� ������ �ܿ� ����ִ� �������� ���� �־����� ��, ȿ�ָ� ���� ���� ���� ���� �����ָ� ���� �� �ֵ��� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
	���� ��� 6���� ������ ���� �ְ�, ������ �ܿ� ������� 6, 10, 13, 9, 8, 1 ��ŭ�� �����ְ� ��� ���� ��, 
	ù ��°, �� ��°, �� ��°, �ټ� ��° ������ ���� �����ϸ� �� ������ ���� 33���� �ִ�� ���� �� �ִ�.

�Է�
	ù° �ٿ� ������ ���� ���� n�� �־�����. (1 �� n �� 10,000) 
	��° �ٺ��� n+1��° �ٱ��� ������ �ܿ� ����ִ� �������� ���� ������� �־�����. 
	�������� ���� 1,000 ������ ���� �ƴ� �����̴�.

���
	ù° �ٿ� �ִ�� ���� �� �ִ� �������� ���� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int GetMax(int A, int B, int C = 0)
{
	A = A > C ? A : C;
	return A > B ? A : B;
}

int main()
{
	int N;
	vector<int> quantity;
	vector<int> result;
	int maxResult = 0;

	cin >> N;
	quantity.resize(N);
	result.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> quantity[i];

	result[0] = quantity[0];
	if(N>=2)
		result[1] = quantity[0] + quantity[1];
	maxResult = GetMax(result[0], N>=2 ? result[1] : 0);

	if (N >= 2)
	{
		result[2] = GetMax(quantity[0], quantity[1]) + quantity[2];
		if (maxResult < result[2])
			maxResult = result[2];
		if (N >= 3)
		{
			result[3] = GetMax(result[1] , result[0] + quantity[2]) + quantity[3];
			if(maxResult < result[3])
				maxResult = result[3];
		}
	}

	for (int i = 4; i < N; ++i)
	{
		result[i] = GetMax(result[i - 2] + quantity[i],
						   result[i - 3] + quantity[i - 1] + quantity[i],
						   result[i - 4] + quantity[i - 1] + quantity[i]);
		if (maxResult < result[i])
			maxResult = result[i];
	}

	cout << maxResult;

	return 0;
}
