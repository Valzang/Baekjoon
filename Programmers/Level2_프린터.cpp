#include <iostream>
#include <vector>

using namespace std;

/*

1. 들어온 location 번째의 우선순위 파악
2. 중요도 높은 9부터 현재 우선순위 까지의 개수 파악
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

		// 출력할 때
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