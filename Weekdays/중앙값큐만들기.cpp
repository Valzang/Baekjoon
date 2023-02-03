#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CustomQueue
{
private:
	vector<int> sortedQueue;

	int GetMidIndex()
	{
		int size = sortedQueue.size();
		return size % 2 == 0 ? size / 2 - 1 : (size / 2);
	}

	int BinarySearch(int x)
	{
		int max = sortedQueue.size();
		if (max == 0)
			return 0;
		int mid = max / 2;
		int min = 0;
		if (max % 2 == 0)
			--mid;

		--max;

		while (min <= max)
		{
			if (sortedQueue[mid] == x)
				return mid;

			if (sortedQueue[mid] < x)
				min = mid + 1;
			else
				max = mid - 1;

			mid = (min + max) / 2;
		}

		return mid;
	}

public:
	string Push(int x)
	{
		int index = BinarySearch(x);
		int size = sortedQueue.size();
		if (index == 0)
		{
			if (size == 0)
				sortedQueue.push_back(x);
			else
				sortedQueue.insert(sortedQueue.begin() + (sortedQueue[0] < x ? 1 : 0), x);

			return to_string(sortedQueue[GetMidIndex()]);
		}
		else if (sortedQueue[index] < x)
			++index;

		if(index >= size)
			sortedQueue.push_back(x);
		else
			sortedQueue.insert(sortedQueue.begin() + index, x);

		return to_string(sortedQueue[GetMidIndex()]);
	}

	string Pop()
	{
		int size = sortedQueue.size();
		
		if (size == 0)
			return "NO ITEM";

		sortedQueue.erase(sortedQueue.begin() + GetMidIndex());
		return size <= 1 ? "NO ITEM" : to_string(sortedQueue[GetMidIndex()]);
	}

	string Size()
	{
		return to_string(sortedQueue.size());
	}

	
};

int main()
{
	int N;
	vector<string> order;
	vector<string> results;
	CustomQueue queue;

	cin >> N;
	cin.ignore();
	order.resize(N);

	for (int i = 0; i < N; ++i)
	{
		getline(cin, order[i]);
		switch (order[i].size())
		{
			case 3:
				results.push_back(queue.Pop());
				break;
			case 4:
				results.push_back(queue.Size());
				break;
			default:
				string str = order[i].substr(5, order[i].size() - 5);
				results.push_back(queue.Push(stoi(str)));
				break;
		}
	}

	cout << "=====================================" << '\n';

	for (int i = 0; i < (int)results.size(); ++i)
		cout << results[i] << '\n';


	return 0;
}