/*

����
	�����̴� �ſ� ��ڱ� ������, ȿ���̿��� ������ �̸�Ƽ���� S�� �������� �Ѵ�.	
	�����̴� �̹� ȭ�鿡 �̸�Ƽ�� 1���� �Է��ߴ�. 
	
	����, ������ ���� 3���� ���길 ����ؼ� �̸�Ƽ���� S�� ����� ������ �Ѵ�.
	
	- ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 �����Ѵ�.
	- Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
	- ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.

	��� ������ 1�ʰ� �ɸ���. 
	
	��, Ŭ�����忡 �̸�Ƽ���� �����ϸ� ������ Ŭ�����忡 �ִ� ������ ����Ⱑ �ȴ�. 	
	Ŭ�����尡 ����ִ� ���¿��� �ٿ��ֱ⸦ �� �� ������, �Ϻθ� Ŭ�����忡 ������ ���� ����. 
	
	����, Ŭ�����忡 �ִ� �̸�Ƽ�� �� �Ϻθ� ������ �� ����. 
	ȭ�鿡 �̸�Ƽ���� �ٿ��ֱ� �ϸ�, Ŭ�����忡 �ִ� �̸�Ƽ���� ������ ȭ�鿡 �߰��ȴ�.
	
	�����̰� S���� �̸�Ƽ���� ȭ�鿡 ����µ� �ɸ��� �ð��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
	ù° �ٿ� S (2 �� S �� 1000) �� �־�����.

���
	ù° �ٿ� �̸�Ƽ���� S�� ����� ���� �ʿ��� �ð��� �ּڰ��� ����Ѵ�.

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