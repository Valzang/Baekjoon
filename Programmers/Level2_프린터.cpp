#include <iostream>
#include <vector>

using namespace std;

/*

1. ���� location ��°�� �켱���� �ľ�
2. �߿䵵 ���� 9���� ���� �켱���� ������ ���� �ľ�
3. 


priorities			location	return
[2, 1, 3, 2]		2			1

=>
	1, 3, 2 ,2
	3, 2, 2, 1

[1, 1, 9, 1, 1, 1]	0			5

*/

int solution(vector<int> priorities, int location) 
{
	int answer = 0;

	while (true)
	{
		int first = priorities.front();
		priorities.erase(priorities.begin());
		location = location < 0 ? priorities.size() - 1 : (int)location - 1;
		for (int i = 0; i < priorities.size(); ++i)
		{
			if (priorities[i] > first)
			{
				priorities.push_back(first);
				first = 0;
				break;
			}
		}

		// ����� ��
		if (first != 0)
		{
			++answer;			
			if (location < 0)
				break;
		}		
	}
	return answer;
}

int main()
{
	vector<int> vec = { 1,1,9,1,1,1 };
	int location = 0;

	cout << solution(vec, location);


	return 0;
}