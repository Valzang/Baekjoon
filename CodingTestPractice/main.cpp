#include <iostream>
#include <string>

using namespace std;

/*
��ȣ�� �ٸ��� ¦�������ٴ� ���� '(' ���ڷ� �������� �ݵ�� ¦��� ')' ���ڷ� ������ �Ѵٴ� ���Դϴ�. ���� ���

"()()" �Ǵ� "(())()" �� �ùٸ� ��ȣ�Դϴ�.
")()(" �Ǵ� "(()(" �� �ùٸ��� ���� ��ȣ�Դϴ�.
'(' �Ǵ� ')' �θ� �̷���� ���ڿ� s�� �־����� ��, ���ڿ� s�� �ùٸ� ��ȣ�̸� true�� return �ϰ�, 
�ùٸ��� ���� ��ȣ�̸� false�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.
*/

bool solution(string s)
{
	bool answer = true;

	int openCount = 1;
	int closeCount = 0;
	// [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.

	if (s[0] == ')')
		return false;

	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == '(')
			++openCount;
		else
		{
			++closeCount;
			if (closeCount > openCount)
				return false;
		}
	}

	return closeCount == openCount;
}

int main()
{
	cout << solution("()()");
	cout << solution("(())()");
	cout << solution(")()(");
	cout << solution("(()(");

	return 0;
}
