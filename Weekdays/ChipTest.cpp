#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;


int T, L;

int GetDiffCount(vector<vector<int>> chipByte)
{
	int count = 0;
	for (int i = 0; i < L; ++i)
	{
		// 8��Ʈ�� �ٲ� �� string���� ����
		string first = bitset<8>(chipByte[0][i]).to_string();
		string second = bitset<8>(chipByte[1][i]).to_string();
		string third = bitset<8>(chipByte[2][i]).to_string();
		
		for (int i = 0; i < 8; ++i)
		{
			// �ϳ��� �ٸ� �� ���� ����
			if (first[i] != second[i] || first[i] != third[i] || second[i] != third[i])
				++count;
		}
	}

	return count;	
}

void StringSplit(vector<vector<int>>& chipByte)
{
	for (int j = 0; j < 3; ++j)
	{
		string results = "", data = "";
		cin >> results;
		for (int i = 0; i < results.length(); ++i)
		{
			if (results[i] != '-')
				data.push_back(results[i]);
			else
			{
				chipByte[j].push_back(stoi(data));
				data.clear();
			}
		}
		if (!data.empty())
			chipByte[j].push_back(stoi(data));
	}
}

int main()
{
	vector<int> results;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{		
		vector<vector<int>> chipByte;
		cin >> L;
		chipByte.resize(3);
		StringSplit(chipByte);
		results.push_back(GetDiffCount(chipByte));
	}
	
	cout << "���======================" << '\n';
	for (int i = 0; i < results.size(); ++i)
		cout << results[i] << '\n';

	return 0;
}