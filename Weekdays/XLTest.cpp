#include <iostream>

using namespace std;

void ReverseWords(char* output, int outputArraySize, const char* input)
{
	if (output == nullptr)
		output = new char[outputArraySize+3]; // 28
	int max = outputArraySize - 1;

	output[outputArraySize] = '\0';
	int start = 0;

	for (int i = 0; i <= outputArraySize; ++i)
	{
		if (input[i] == ' ' || i == outputArraySize)
		{
			int end = i - 1 ;
			for (int j = start; j <= end; ++j)
			{
				int cur = max - start - end + j;
				output[cur] = input[j];
			}
			if(i != outputArraySize)
				output[max - i] = ' ';
			start = i + 1;
		}
	}

	cout << output << '\n';
	delete[] output;
}

void IntToStr(char* output, int outputArraySize, int input)
{
	if (output == nullptr)
		output = new char[outputArraySize + 1];

	int size = outputArraySize;
	output[size--] = '\0';

	while (input != 0)
	{
		char curChar = '0' + (input % 10);
		input /= 10;
		output[size--] = curChar;
	}

	cout << output << '\n';
	delete[] output;
}

struct ListNode
{
	int val;
	ListNode* nextNode;
	ListNode(int x, ListNode* next) : val(x), nextNode(next) {}
};

ListNode* InsertionSort(ListNode* head)
{	
	//ListNode* curNode = head->nextNode;
	ListNode* prevNode = head->nextNode;

	ListNode* curNode = head->nextNode;
	ListNode* firstNode = head;
	while (curNode != nullptr)
	{		
		firstNode = head->nextNode;
		if (firstNode->val >= curNode->nextNode->val)
			continue;
	}

	while (curNode->nextNode != nullptr)
	{	
		ListNode* startNode = firstNode;
		
		while (curNode->val > startNode->val
			   && curNode != startNode)
		{
			prevNode = startNode;
			startNode = startNode->nextNode;
		}
		if (prevNode != firstNode)
		{
			prevNode->nextNode = curNode;
			curNode->nextNode = startNode;
		}
		
		//prevNode = curNode;
		//curNode = curNode->nextNode;
	}

	return head;
}

int GetLength(const char* string)
{
	int size = 0;
	while (string[size] != '\0')
		++size;

	return size;
}

int GetLength(int arr)
{
	int size = 0;
	while (arr != 0)
	{
		arr /= 10;
		++size;
	}

	return size;
}

int main()
{
	const char* test1 = "hello world this is inhahrd";
	char* reverse = nullptr;
	int size = GetLength(test1);
	ReverseWords(reverse, size, test1);

	int test2 = 1819;
	size = GetLength(test2);
	IntToStr(reverse, size, test2);

}