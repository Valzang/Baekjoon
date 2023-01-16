/*

����
	�۳⿡ �̾� ���ο� ���ڿ� ������ �ִ�. ������ ���� ����� �Ʒ��� ����.

	1. ���ĺ� �ҹ��ڷ� �̷���� ���ڿ� W�� �־�����.
	2. ���� ���� K�� �־�����.
	3. � ���ڸ� ��Ȯ�� K���� �����ϴ� ���� ª�� ���� ���ڿ��� ���̸� ���Ѵ�.
	4. � ���ڸ� ��Ȯ�� K���� �����ϰ�, ���ڿ��� ù ��°�� ������ ���ڰ� �ش� ���ڷ� ���� ���� �� ���� ���ڿ��� ���̸� ���Ѵ�.
	���� ���� ������� ������ Tȸ �����Ѵ�.

�Է�
	���ڿ� ������ �� T�� �־�����. (1 �� T �� 100)
	���� �ٺ��� 2���� �� ���� ���ڿ� W�� ���� K�� �־�����. (1 �� K �� |W| �� 10,000)

���
	T���� �� ���� ���ڿ� ������ 3���� 4������ ���� ���� ���ڿ��� ���̸� ������ ���̿� �ΰ� ����Ѵ�.
	���� �����ϴ� ���� ���ڿ��� ���� �� -1�� ����Ѵ�.


�߰� ����
	3���� 4���� ���, ��� �� ���� �����̶�� ���� �ȴ�.

*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	string W = "";
	vector<vector<int>> alphabetCount;
	vector<vector<int>> alphabetOverK;
	vector<int> finalResults;

	
	int K = 0;
	int T;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> W >> K;
		alphabetOverK.clear();
		alphabetCount.clear();
		alphabetCount.resize(26);

		// ���ĺ� ī��Ʈ ��Ƶ� ����
		for (int j = 0; j < W.length(); ++j)
			alphabetCount[W[j] - 'a'].push_back(j);

		// ���ĺ� ī��Ʈ�� K �̻��� ���ĺ��� �ε������� ��Ƶ� ����
		for (int j = 0; j < alphabetCount.size(); ++j)
		{
			if (alphabetCount[j].size() >= K)
				alphabetOverK.push_back(alphabetCount[j]);
		}

		if (alphabetOverK.size() == 0)
			finalResults.push_back(-1);
		else
		{
			int shortest = 10000;
			int longest = 0;
			// ��� ��Ƶ� ����
			for (int j = 0; j < alphabetOverK.size(); ++j)
			{
				for (int k = 0; k+K-1 < alphabetOverK[j].size(); ++k)
				{
					int temp = alphabetOverK[j][k + K - 1] - alphabetOverK[j][k] + 1;
					shortest = temp < shortest ? temp : shortest;
					longest = temp > longest ? temp : longest;
				}
			}
			finalResults.push_back(shortest);
			finalResults.push_back(longest);
		}
	}

	bool needNewLine = false;
	for (int i = 0; i < finalResults.size(); ++i)
	{
		cout << finalResults[i];

		if (finalResults[i] != -1 && !needNewLine)
		{
			cout << " ";
			needNewLine = true;
		}
		else
		{
			cout << '\n';
			needNewLine = false;
		}
	}


	return 0;
}