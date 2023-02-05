/*

문제
	영선이는 매우 기쁘기 때문에, 효빈이에게 스마일 이모티콘을 S개 보내려고 한다.	
	영선이는 이미 화면에 이모티콘 1개를 입력했다. 
	
	이제, 다음과 같은 3가지 연산만 사용해서 이모티콘을 S개 만들어 보려고 한다.
	
	- 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
	- 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
	- 화면에 있는 이모티콘 중 하나를 삭제한다.

	모든 연산은 1초가 걸린다. 
	
	또, 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기가 된다. 	
	클립보드가 비어있는 상태에는 붙여넣기를 할 수 없으며, 일부만 클립보드에 복사할 수는 없다. 
	
	또한, 클립보드에 있는 이모티콘 중 일부를 삭제할 수 없다. 
	화면에 이모티콘을 붙여넣기 하면, 클립보드에 있는 이모티콘의 개수가 화면에 추가된다.
	
	영선이가 S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.

입력
	첫째 줄에 S (2 ≤ S ≤ 1000) 가 주어진다.

출력
	첫째 줄에 이모티콘을 S개 만들기 위해 필요한 시간의 최솟값을 출력한다.

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int S;

vector<int> minTime;
bool visited[2000][2000];

int BFS()
{
	queue<pair<int, pair<int, int>>> Q;
	visited[1][0] = true;
	Q.push(make_pair(1, make_pair(0, 0)));

	while (!Q.empty())
	{
		int emojiCount = Q.front().first;
		int clipboard = Q.front().second.first;
		int time = Q.front().second.second;
		Q.pop();

		if (emojiCount == S)
			return time;

		if (emojiCount > 0 && emojiCount < 2000)
		{
			if (!visited[emojiCount][emojiCount])
			{
				visited[emojiCount][emojiCount] = true;
				Q.push(make_pair(emojiCount, make_pair(emojiCount, time + 1)));
			}
			if (emojiCount + clipboard < 2000 && !visited[emojiCount + clipboard][clipboard])
			{
				visited[emojiCount + clipboard][clipboard] = true;
				Q.push(make_pair(emojiCount + clipboard, make_pair(clipboard, time + 1)));
			}
		}
		
		if (emojiCount > 1 && !visited[emojiCount - 1][clipboard])
		{
			visited[emojiCount - 1][clipboard] = true;
			Q.push(make_pair(emojiCount - 1, make_pair(clipboard, time + 1)));
		}
	}
}

int main()
{
	cin >> S;

	cout << BFS();

	return 0;
}