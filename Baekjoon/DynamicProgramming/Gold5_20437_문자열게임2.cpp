/*

����
	�۳⿡ �̾� ���ο� ���ڿ� ������ �ִ�. ������ ���� ����� �Ʒ��� ����.

	���ĺ� �ҹ��ڷ� �̷���� ���ڿ� W�� �־�����.
	���� ���� K�� �־�����.
	� ���ڸ� ��Ȯ�� K���� �����ϴ� ���� ª�� ���� ���ڿ��� ���̸� ���Ѵ�.
	� ���ڸ� ��Ȯ�� K���� �����ϰ�, ���ڿ��� ù ��°�� ������ ���ڰ� �ش� ���ڷ� ���� ���� �� ���� ���ڿ��� ���̸� ���Ѵ�.
	���� ���� ������� ������ Tȸ �����Ѵ�.

�Է�
	���ڿ� ������ �� T�� �־�����. (1 �� T �� 100)
	���� �ٺ��� 2���� �� ���� ���ڿ� W�� ���� K�� �־�����. (1 �� K �� |W| �� 10,000)

���
	T���� �� ���� ���ڿ� ������ 3���� 4������ ���� ���� ���ڿ��� ���̸� ������ ���̿� �ΰ� ����Ѵ�.
	���� �����ϴ� ���� ���ڿ��� ���� �� -1�� ����Ѵ�.

*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	string W = "";
	vector<vector<int>> alphabetCount;
	vector<pair<int,vector<int>>> alphabetOverK;
	vector<vector<int>> results;

	
	alphabetCount.resize(26);		
	
	int K = 0;
	int T;

	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> W >> K;

		// ���ĺ� ī��Ʈ ��Ƶ� ����
		for (int i = 0; i < W.length(); ++i)
			alphabetCount[W[i] - 'a'].push_back(i);

		// ���ĺ� ī��Ʈ�� K �̻��� ���ĺ��� ��Ƶ� ����
		for (int i = 0; i < alphabetCount.size(); ++i)
		{
			if (alphabetCount[i].size() >= K)
				alphabetOverK.push_back(make_pair(i + 'a', alphabetCount[i]));
		}

		// ��� ��Ƶ� ����
		results.resize(alphabetOverK.size());

	}


	return 0;
}