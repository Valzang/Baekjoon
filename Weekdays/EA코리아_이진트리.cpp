#include <iostream>
#include <map>

#include <crtdbg.h>

using namespace std;



struct tree
{
	int x;
	tree* l;
	tree* r;

	tree(int a, tree* _left = nullptr, tree* _right = nullptr)
	{
		x = a;
		l = _left;
		r = _right;
	}
};


int DownTree(tree* T, map<int, int> subTreeMap)
{
	int count = subTreeMap.size();
	map<int, int> leftMap = subTreeMap;
	map<int, int> rightMap = subTreeMap;
	if (T->l != nullptr)
	{
		leftMap.insert(make_pair(T->l->x, 1));
		int tempCount = DownTree(T->l, leftMap);
		if (tempCount > count)
			count = tempCount;
	}
	if (T->r != nullptr)
	{
		rightMap.insert(make_pair(T->r->x, 1));
		int tempCount = DownTree(T->r, rightMap);
		if (tempCount > count)
			count = tempCount;
	}	
	return count;
}

void DeleteTree(tree* T)
{
	if (T == nullptr)
		return;

	DeleteTree(T->l);
	DeleteTree(T->r);

	delete T;
	T = nullptr;	
	
}

int solution(tree* T)
{
	map<int, int> treeMap;
	if (T == nullptr)
		return 0;
	treeMap.insert(make_pair(T->x, 1));
	return DownTree(T, treeMap);

}


// 구분되는 수는 최대 3임.
// N은 정수로, 1~50,000
// 트리의 층은 0~ 3,500



// int solution(tree *T);
// T는 N개의 노드를 가짐. 구분되는 수가 가장 큰 경우의 값을 반환함.
// 시간 & 공간복잡도 최악의 경우가 O(N)

int main()
{
	/// res = 3
	/*
	tree* t = new tree(4);
	t->l = new tree(5);
	t->r = new tree(6);

	t->l->l = new tree(4);
	t->l->l->l = new tree(5);

	t->r->l = new tree(1);
	t->r->r = new tree(6);
	*/

	// res = 4
	/*
	tree* t = new tree(4);
	t->l = new tree(3);
	t->r = new tree(6);

	t->l->l = new tree(2);
	t->l->l->l = new tree(1);

	t->r->l = new tree(1);
	t->r->r = new tree(6);
	*/

	/// res = 5
	/*
	tree* t = new tree(4);
	t->l = new tree(5);
	t->l->l = new tree(4);
	t->l->l->l = new tree(5);


	t->r = new tree(6);
	t->r->l = new tree(1);
	t->r->l->l = new tree(8);
	t->r->l->l->l = new tree(10);

	t->r->l->r = new tree(7);

	t->r->r = new tree(6);
	t->r->r->r = new tree(3);
	*/

	/// res = 6
	/*
	tree* t = new tree(3);
	t->l = new tree(4);
	t->l->l = new tree(3);
	t->l->l->l = new tree(4);

	t->l->r = new tree(1);
	t->l->r->l = new tree(3);
	t->l->r->r = new tree(10);
	t->l->r->r->r = new tree(20);
	t->l->r->r->r->r = new tree(15);

	t->r = new tree(5);
	t->r->l = new tree(2);

	t->r->r = new tree(2);
	t->r->r->r = new tree(20);
	t->r->r->r->r = new tree(10);
	*/

	// res = 7
	tree* t = new tree(3);
	t->l = new tree(4);
	t->l->l = new tree(3);
	t->l->l->l = new tree(4);

	t->l->r = new tree(1);
	t->l->r->l = new tree(3);
	t->l->r->r = new tree(10);
	t->l->r->r->l = new tree(4);
	t->l->r->r->l->l = new tree(5);
	t->l->r->r->r = new tree(20);
	t->l->r->r->r->l = new tree(11);
	t->l->r->r->r->r = new tree(15);

	t->r = new tree(5);
	t->r->l = new tree(2);

	t->r->r = new tree(2);
	t->r->r->r = new tree(20);

	t->r->r->r->l = new tree(10);
	t->r->r->r->l->l = new tree(12);
	t->r->r->r->l->r = new tree(13);

	t->r->r->r->r = new tree(11);
	t->r->r->r->r->l = new tree(14);
	t->r->r->r->r->l->l = new tree(288);
	t->r->r->r->r->l->r = new tree(14);
	t->r->r->r->r->r = new tree(11);

	cout << "최대 개수 : " << solution(t);

	DeleteTree(t);

	_CrtDumpMemoryLeaks();

	return 0;
}