#include <iostream>
#include <string>
#include <vector>
#include <map>

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
	int count = priorities.size();

	int curPrior = 9;
	int nextPrior = 9;
	int nextPriorIndex = -1;

	vector<int> after;

	int i = 0;
	while (true)
	{
		if (priorities[i] == curPrior)
		{
			after.push_back(i);
		}
		else if(priorities[i] < nextPrior)
		{
			nextPrior = priorities[i];
			nextPriorIndex = i;
		}
		i = i >= priorities.size() ? 0 : i + 1;
		--count;
		if (count <= 0)
		{
			i = nextPriorIndex;
			curPrior = nextPrior;
			count = priorities.size();
		}
	}




	return answer;
}

int main()
{



	return 0;
}