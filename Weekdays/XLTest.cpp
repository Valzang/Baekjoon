#include <iostream>

using namespace std;

void ReverseWords(char* output, int outputArraySize, const char* input)
{
	// ������ ���ڴ� '\0'�����ϹǷ� ���� ũ�⺸�� 1 ũ��.
	if (output == nullptr)
		output = new char[outputArraySize+1];
	
	int max = outputArraySize - 1;

	output[outputArraySize] = '\0';
	int start = 0;

	for (int i = 0; i <= outputArraySize; ++i)
	{
		// �������� �����ϰų�, ���鹮�ڷ� ���� �ܾ ���� ���
		if (input[i] == ' ' || i == outputArraySize)
		{
			// �ܾ��� ����
			int end = i - 1 ;

			// ������ �ܾ��� ���̸�ŭ ���� ������ �־��ش�.
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
	// ������ ���ڴ� '\0'�����ϹǷ� ���� ũ�⺸�� 1 ũ��.
	if (output == nullptr)
		output = new char[outputArraySize + 1];

	int size = outputArraySize;
	output[size--] = '\0';

	// �������� ���� 1�� �ڸ����� ����ؼ� �־��ְ�, ������ ���� ���� �۾���.
	while (input != 0)
	{
		char curChar = '0' + (input % 10);
		input /= 10;
		output[size--] = curChar;
	}

	cout << "\"" << output << "\"" << '\n';
	delete[] output;
}

struct ListNode
{
	int val;
	ListNode* nextNode;
	ListNode(int x, ListNode* next = nullptr) : val(x), nextNode(next) {}
	ListNode* SetNext(ListNode* next)
	{
		nextNode = next;
		return nextNode;
	}
	ListNode* SetNext(int value)
	{
		nextNode = new ListNode(value);
		return nextNode;
	}
};

void DeleteNode(ListNode* head)
{
	if (head->nextNode != nullptr)
		DeleteNode(head->nextNode);

	if (head != nullptr)
	{
		delete head;
		head = NULL;
	}	
}

void PrintNode(ListNode* head)
{
	cout << "head";
	ListNode* current = head->nextNode;
	while (current != nullptr)
	{
		cout << " -> " << current->val;
		current = current->nextNode;
	}
	cout << '\n';
}

ListNode* InsertionSort(ListNode* head)
{	
	// ��ȯ�� ��带 ���� �������.
	ListNode* sortedNode = new ListNode(head->val);
	if (head->nextNode != nullptr)
	{
		sortedNode->SetNext(head->nextNode->val);
		ListNode* startNode = head->nextNode;		
		// ���� ������ ������ �����ϸ鼭, �� ��� ���� ���ؼ� �� ��忡 �������.
		while (startNode->nextNode != nullptr)
		{
			startNode = startNode->nextNode;
			ListNode* checkNode = sortedNode->nextNode;
			ListNode* insertionNode = sortedNode;
			while (checkNode != nullptr)
			{
				if (checkNode->val >= startNode->val)
					break;
				insertionNode = insertionNode->nextNode;
				checkNode = checkNode->nextNode;
			}
			insertionNode->SetNext(startNode->val)->SetNext(checkNode);
		}
	}

	DeleteNode(head);

	return sortedNode;
}

int GetNodeCount(ListNode* head)
{
	int count = 0;
	while (head != nullptr)
	{
		head = head->nextNode;
		++count;
	}

	return count;
}

ListNode* FindNthNodeFromLast(ListNode* head, int n)
{
	int nthFromLast = GetNodeCount(head) - n;
	if (n == 0 || nthFromLast <= 0)
	{
		cout << "�߸��� �Ű����� ���� " << n << "�� �ԷµǾ����ϴ�" << '\n';
		exit(1);
	}
	int count = 0;
	while (head != nullptr)
	{
		head = head->nextNode;
		++count;
		if (nthFromLast == count)
			return head;
	}
}

struct TreeNode
{
	int val;
	TreeNode* leftNode;
	TreeNode* rightNode;
	TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(x), leftNode(left), rightNode(right) {}
};

void DeleteTreeNode(TreeNode* head)
{
	if (head->leftNode != nullptr)
		DeleteTreeNode(head->leftNode);
	if (head->rightNode != nullptr)
		DeleteTreeNode(head->rightNode);

	delete head;
	head = NULL;
}

void PreorderTraversal(TreeNode* root)
{
	cout << root->val << ',';
	if(root->leftNode != nullptr)
		PreorderTraversal(root->leftNode);
	if (root->rightNode != nullptr)
		PreorderTraversal(root->rightNode);
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

int FindSingleNumber(int* numbers, int arraySize)
{
	for (int i = 0; i < arraySize - 1;)
	{
		if (numbers[i] == numbers[i + 1])
			i += 2;
		else
			return numbers[i];
	}
}

void RotateRectangle(int* image, int width)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = width-1; j >= 0; --j)
		{
			cout << image[j * width + i];
			if (i != width - 1 || j != 0)
				cout << ", ";
		}
		cout << '\n';
	}
}

int main()
{
	const char* test1 = "hello world this is inhahrd";
	char* reverse = nullptr;
	int size = GetLength(test1);
	cout << "�Է°� : " << test1 << '\n';
	cout << "��ȯ�� : ";
	ReverseWords(reverse, size, test1);
	cout << '\n';

	int test2 = 1819;
	size = GetLength(test2);
	cout << "�Է°� : " << test2 << '\n';
	cout << "��ȯ�� : ";
	IntToStr(reverse, size, test2);
	cout << '\n';

	ListNode* head = new ListNode(0);
	head->SetNext(2)->SetNext(10)->SetNext(7)->SetNext(6)->SetNext(20);
	cout << "�Է°� : ";
	PrintNode(head);
	cout << "��ȯ�� : ";
	head = InsertionSort(head);
	PrintNode(head);
	cout << '\n';
	DeleteNode(head);

	head = new ListNode(0);
	head->SetNext(2)->SetNext(1)->SetNext(3)->SetNext(6)->SetNext(10)->SetNext(5);
	cout << "�Է°� : ";
	PrintNode(head);
	cout << "��ȯ�� : " << FindNthNodeFromLast(head, 2)->val << '\n';		
	DeleteNode(head);

	cout << '\n' << "Ʈ�� ��� : ";
	TreeNode* thead = new TreeNode(10, new TreeNode(7, new TreeNode(2), new TreeNode(8)), new TreeNode(16, new TreeNode(11), new TreeNode(18)));
	PreorderTraversal(thead);
	DeleteTreeNode(thead);
	cout << '\n' << '\n';

	int numbers[11] = { 1, 1, 2, 2, 8, 8, 3, 5, 5, 0, 0 };
	int length = sizeof(numbers) / sizeof(int);
	cout << "�Է°� : ";
	for (int i = 0; i < length; ++i)
	{
		cout << numbers[i];
		if (i == length - 1)
			cout << '\n';
		else
			cout << ",";
	}
	cout << "��ȯ�� : " << FindSingleNumber(numbers, length) << '\n';

	int image[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int imgSize = 3;
	cout << '\n';
	RotateRectangle(image, imgSize);

	return 0;

}