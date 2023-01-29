/*

����
	ũ�Ⱑ N��M�� ���̰� �ְ�, ���̴� 1��1ũ���� ĭ���� �������� �ִ�. 
	�� ������ �� ĭ ���� 1��1��1 ũ���� ������ü�� ���� 3���� ������ �������.
	
	������ �� ĭ�� ���� ������ü�� ������ �־����� ��, �� ������ �ѳ��̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.	
	
	���� �׸��� 3��3 ũ���� ���� ���� ������ü�� ���� ���̰�, �ѳ��̴� 60�̴�.

�Է�
	ù° �ٿ� ������ ũ�� N, M�� �־�����. ��° �ٺ��� N���� �ٿ��� ������ �� ĭ�� ���� ������ü�� ���� �־�����.

���
	ù° �ٿ� ������ �ѳ��̸� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	vector<vector<int>> hexa;
	int result = 0;

	cin >> N >> M;
	hexa.resize(N);
	for (int i = 0; i < N; ++i)
	{
		hexa[i].resize(M);

		for (int j = 0; j < M; ++j)
		{
			cin >> hexa[i][j];


			// ��, �Ʒ����� �� ����
			if (hexa[i][j] != 0)
				result += 2;

			if (j > 0 && hexa[i][j - 1] != hexa[i][j])
			{
				int diff = hexa[i][j] - hexa[i][j - 1];				
				result += (diff < 0 ? -diff : diff);				
			}
		
		}
		result += hexa[i][0] + hexa[i][M - 1];
	}

	// ��, �Ŀ��� �� ����
	for (int j = 0; j < M; ++j)
	{

		for (int i = 0; i < N; ++i)
		{
			if (i > 0 && hexa[i-1][j] != hexa[i][j])
			{
				int diff = hexa[i][j] - hexa[i-1][j];
				result += (diff < 0 ? -diff : diff);
			}

		}
		result += hexa[0][j] + hexa[N-1][j];
	}
	

	cout << result;

	return 0;

}
