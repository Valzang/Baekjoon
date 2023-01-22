/*
����
	�ν��̴� �����п����� �ܾ� ���� ������ Ǫ�� ������ �޾Ҵ�.	
	�ܾ� ���� ������ N���� �ܾ�� �̷���� ������, �� �ܾ�� ���ĺ� �빮�ڷθ� �̷���� �ִ�. 
	
	�̶�, �� ���ĺ� �빮�ڸ� 0���� 9������ ���� �� �ϳ��� �ٲ㼭 N���� ���� ���ϴ� �����̴�. 
	���� ���ĺ��� ���� ���ڷ� �ٲ�� �ϸ�, �� �� �̻��� ���ĺ��� ���� ���ڷ� �ٲ������ �� �ȴ�.	

	���� ���, GCF + ACDEB�� ����Ѵٰ� �� ��, 
	A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7�� �����Ѵٸ�, �� ���� ���� 99437�� �Ǿ �ִ밡 �� ���̴�.

	N���� �ܾ �־����� ��, �� ���� ���� �ִ�� ����� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� �ܾ��� ���� N(1 �� N �� 10)�� �־�����. 
	��° �ٺ��� N���� �ٿ� �ܾ �� �ٿ� �ϳ��� �־�����. 
	
	�ܾ�� ���ĺ� �빮�ڷθ� �̷�����ִ�. 
	��� �ܾ ���ԵǾ� �ִ� ���ĺ��� �ִ� 10���̰�, ���� �ִ� ���̴� 8�̴�. 
	���� �ٸ� ���ڴ� ���� �ٸ� ���ڸ� ��Ÿ����.

���
	ù° �ٿ� �־��� �ܾ��� ���� �ִ��� ����Ѵ�.


*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int N;

	vector<int> result;
	result.resize(26);

	vector<string> alphabet;

	cin >> N;
	alphabet.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> alphabet[i];		
		for (int j = 0; j < (int)alphabet[i].size(); ++j)
			result[(int)(alphabet[i][j] - 'A')] += (int)pow(10, (int)alphabet[i].size() - 1 - j);
	}

	sort(result.begin(), result.end(), compare);

	int k = 0;
	int num = 9;
	int sum = 0;
	while (result[k] != 0)
		sum += result[k++] * num--;

	cout << sum;

	return 0;
}