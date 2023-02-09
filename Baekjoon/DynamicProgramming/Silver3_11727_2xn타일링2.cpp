/*

����
	2��n ���簢���� 1��2, 2��1�� 2��2 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	�Ʒ� �׸��� 2��17 ���簢���� ä�� �Ѱ��� ���̴�.

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

	result.resize(n + 1);
	result[1] = 1;
	for (int i = 2; i <= n; ++i)
		result[i] = (i % 2 == 0 ? result[i - 1] * 2 + 1 : result[i - 1] * 2 - 1) % divider;
	

	cout << result[n];

	return 0;
}