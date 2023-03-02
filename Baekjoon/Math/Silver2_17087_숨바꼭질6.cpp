/*

����
	�����̴� ���� N��� ���ٲ����� �ϰ� �ִ�. 
	�����̴� ���� �� S�� �ְ�, ������ A1, A2, ..., AN�� �ִ�.
	
	�����̴� �ɾ �̵��� �� �� �ִ�. 
	�������� ��ġ�� X�϶� �ȴ´ٸ� 1�� �Ŀ� X+D�� X-D�� �̵��� �� �ִ�. 
	�������� ��ġ�� ������ �ִ� ��ġ�� ������, ������ ã�Ҵٰ� �Ѵ�.
	
	��� ������ ã������ D�� ���� ���Ϸ��� �Ѵ�. ������ D�� �ִ��� ���غ���.

�Է�
	ù° �ٿ� N(1 �� N �� 105)�� S(1 �� S �� 109)�� �־�����. 
	��° �ٿ� ������ ��ġ Ai(1 �� Ai �� 109)�� �־�����. 
	������ ��ġ�� ��� �ٸ���, �������� ��ġ�� ���� �ʴ�.

���
	������ D���� �ִ��� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b = 0)
{
	if (b <= 0)
		return a;
	return GCD(b, a % b);
}

int main()
{
	int N = 0, S = 0;
	int gcd = 0;
	vector<int> bros;

	cin >> N >> S;
	bros.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> bros[i];
		bros[i] = S > bros[i] ? S - bros[i] : bros[i] - S;
		gcd = gcd != 0 ? GCD(gcd, bros[i]) : bros[i];
	}

	cout << gcd;

	return 0;
}