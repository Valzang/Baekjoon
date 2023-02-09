/*

����
	2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.	
	�Ʒ� �׸��� 2��5 ũ���� ���簢���� ä�� �� ���� ����� ���̴�.

�Է�
	ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

���
	ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	int divider = 10007;
	vector<int> result;	
	cin >> n;

	result.resize(n+1);
	result[1] = 1;
	if (n > 1)
		result[2] = 2;
	for (int i = 3; i <= n; ++i)
		result[i] = (result[i - 1] % divider + result[i - 2] % divider) % divider;

	cout << result[n];

	return 0;
}