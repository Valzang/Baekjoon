/*

����
	1742��, ������ �Ƹ��߾� ���а� ũ����Ƽ�� ������� �����ϸ�Ʈ ���Ϸ����� ������ ���� ������ �����ϴ� ������ ���´�.
	
	4���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
	���� ��� 8�� 3 + 5�� ��Ÿ�� �� �ְ�, 3�� 5�� ��� Ȧ���� �Ҽ��̴�. 
	
	��, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 �̴�.
	
	�� ������ ������ �ذ���� ���� �����̴�.
	
	1,000,000 ������ ��� ¦���� ���ؼ�, �� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	�Է��� �ϳ� �Ǵ� �� �̻��� �׽�Ʈ ���̽��� �̷���� �ִ�. 
	�׽�Ʈ ���̽��� ������ 100,000���� ���� �ʴ´�.

	�� �׽�Ʈ ���̽��� ¦�� ���� n �ϳ��� �̷���� �ִ�. (6 �� n �� 1000000)

	�Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
	�� �׽�Ʈ ���̽��� ���ؼ�, n = a + b ���·� ����Ѵ�. 
	�� ��, a�� b�� Ȧ�� �Ҽ��̴�. ���ڿ� �����ڴ� ���� �ϳ��� ���еǾ��� �ִ�. 
	
	����, n�� ���� �� �ִ� ����� ���� �������, b-a�� ���� ū ���� ����Ѵ�. 
	
	��, �� Ȧ�� �Ҽ��� ������ n�� ��Ÿ�� �� ���� ��쿡�� "Goldbach's conjecture is wrong."�� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> primeNumbers;
vector<bool> isCompositeVector;


void SieveOfEratosthenes()
{
	int max = 1000000;
	primeNumbers.resize(1000);
	for (int i = 2; i <= max; ++i)
	{
		if (isCompositeVector[i])
			continue;

		primeNumbers.push_back(i);

		for (int j = i * 2; j <= max; j+=i)
			isCompositeVector[j] = true;
	}
}

void GetAnswer(int number)
{
	int a = 0, b = 0;
	int start = 0;
	do
	{
		a = primeNumbers[start++];
		b = number - a;
		if (!isCompositeVector[b])
		{
			cout << a << " + " << b << '\n';
			return;
		}
	} while (a <= b);

	cout << "Goldbach's conjecture is wrong." << '\n';
}


int main()
{
	int n;
	int count = 0;
	vector<int> testCase;

	isCompositeVector.resize(1000001);
	SieveOfEratosthenes();

	testCase.resize(100000);

	do
	{
		cin >> n;
		testCase[count++] = n;
	} while (n != 0);
	--count;

	for (int i = 0; i < count; ++i)
	{
		cout << testCase[i] << " = ";
		GetAnswer(testCase[i]);
	}

	return 0;
}