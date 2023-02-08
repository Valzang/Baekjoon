/*

����
	0�� 1�θ� �̷���� ���� �������� �Ѵ�. 
	�̷��� ������ �� Ư���� ������ ���� �͵��� �ִµ�, �̵��� ��ģ��(pinary number)�� �Ѵ�. 
	
	��ģ���� ������ ������ �����Ѵ�.
	
	- ��ģ���� 0���� �������� �ʴ´�.
	- ��ģ�������� 1�� �� �� �������� ��Ÿ���� �ʴ´�.
	- ���� ��� 1, 10, 100, 101, 1000, 1001 ���� ��ģ���� �ȴ�. ������ 0010101�̳� 101101�� ���� 1, 2�� ��Ģ�� ����ǹǷ� ��ģ���� �ƴϴ�.
	
	N(1 �� N �� 90)�� �־����� ��, N�ڸ� ��ģ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� N�� �־�����.

���
	ù° �ٿ� N�ڸ� ��ģ���� ������ ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0;
	vector<unsigned long long> pinaryNumber;

	pinaryNumber.resize(3);
	pinaryNumber[1] = 1;
	pinaryNumber[2] = 1;

	cin >> N;
	if (N >= 3)
		pinaryNumber.resize(N+1);

	for (int i = 3; i <= N; ++i)
		pinaryNumber[i] = pinaryNumber[i - 1] + pinaryNumber[i - 2];

	cout << pinaryNumber[N];

	return 0;
}