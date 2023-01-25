/*

����
	N���� ���� �̷���� ���� A1, A2, ..., AN�� �־�����.
	��, ���� �� ���̿� �������� �� �ִ� N-1���� �����ڰ� �־�����. 
	�����ڴ� ����(+), ����(-), ����(��), ������(��)���θ� �̷���� �ִ�.
	
	�츮�� ���� �� ���̿� �����ڸ� �ϳ��� �־, ������ �ϳ� ���� �� �ִ�. 
	�̶�, �־��� ���� ������ �ٲٸ� �� �ȴ�.
	
	���� ���, 6���� ���� �̷���� ������ 1, 2, 3, 4, 5, 6�̰�, 
	�־��� �����ڰ� ����(+) 2��, ����(-) 1��, ����(��) 1��, ������(��) 1���� ��쿡�� �� 60������ ���� ���� �� �ִ�. 
	���� ���, �Ʒ��� ���� ���� ���� �� �ִ�.
	
	1+2+3-4��5��6
	1��2+3+4-5��6
	1+2��3��4-5+6
	1��2��3-4+5+6

	���� ����� ������ �켱 ������ �����ϰ� �տ������� �����ؾ� �Ѵ�. 
	��, �������� ���� ���������� �� ���Ѵ�. ������ ����� ���� ���� C++14�� ������ ������. 
	
	��, ����� �ٲ� �� ���� ���ϰ�, �� ���� ������ �ٲ� �Ͱ� ����. 
	�̿� ����, ���� �� 4���� ����� ����غ��� �Ʒ��� ����.
	
	1+2+3-4��5��6 = 1
	1��2+3+4-5��6 = 12
	1+2��3��4-5+6 = 5
	1��2��3-4+5+6 = 7

	N���� ���� N-1���� �����ڰ� �־����� ��, ���� �� �ִ� ���� ����� �ִ��� �Ͱ� �ּ��� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	
�Է�
	ù° �ٿ� ���� ���� N(2 �� N �� 11)�� �־�����. 
	��° �ٿ��� A1, A2, ..., AN�� �־�����. (1 �� Ai �� 100) 
	��° �ٿ��� ���� N-1�� 4���� ������ �־����µ�, ���ʴ�� ����(+)�� ����, ����(-)�� ����, ����(��)�� ����, ������(��)�� �����̴�.

���
	ù° �ٿ� ���� �� �ִ� ���� ����� �ִ���, ��° �ٿ��� �ּڰ��� ����Ѵ�. 
	�����ڸ� ��� �����־ �׻� -10�ﺸ�� ũ�ų� ����, 10�ﺸ�� �۰ų� ���� ����� ������ �Է¸� �־�����. 
	
	����, �տ������� ������� ��, �߰��� ���Ǵ� ���� ����� �׻� -10�ﺸ�� ũ�ų� ����, 10�ﺸ�� �۰ų� ����.

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> operandVec;
int maxResult = -1000000000;
int minResult = 1000000000;

int Operate(int idx, int A, int B)
{
	switch (idx)
	{
		case 0:
			return A + B;
		case 1:
			return A - B;
		case 2:
			return A * B;
		case 3:
			return A / B;
	}
}

void DFS(vector<int> operatorVec, int value, int count = 0)
{
	if (count + 1 >= (int)operandVec.size())
	{
		if (value < minResult)
			minResult = value;
		if (value > maxResult)
			maxResult = value;
		return;
	}

	for (int i = 0; i < (int)operatorVec.size(); ++i)
	{
		if (operatorVec[i] == 0)
			continue;

		--operatorVec[i];
		DFS(operatorVec, Operate(i, value, operandVec[count + 1]), count + 1);
		++operatorVec[i];

	}
}

int main()
{
	vector<int> operatorVec;
	operatorVec.resize(4);

	cin >> N;

	operandVec.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> operandVec[i];

	for (int i = 0; i < 4; ++i)
		cin >> operatorVec[i];

	DFS(operatorVec, operandVec[0]);

	cout << maxResult << '\n' << minResult;

	return 0;
}