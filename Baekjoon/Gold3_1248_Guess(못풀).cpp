/*
����
	���ӵ� ������ �־����� (a1, a2, ..., an) �̰� ��ȣ ��� S�� ����Ѵ�.
	1<= i <= j <= n �̸�
		ai + �� + aj > 0 �� ��� Sij= "+"
		ai + �� + aj < 0 �� ��� Sij= "-"
		�� �ܴ� Sij = 0

	���� ���, (a1, a2, a3, a4) = ( -1, 5, -4, 2), �� ��� ��ȣ ��� S�� ������ ���� 4*4 ����� �ȴ�.

		1	2	3	4
	1	-	+	0	+
	2	 	+	+	+
	3	 	 	-	-
	4	 	 	 	+

	���ӵ� ������ ��ȣ ����� ������� �� �ִٸ� �� ����� ��ȿ�ϴٰ� �� �� ������ ��ȣ ����� �����ϱ� ����.

	������ �� ������ �ݴ��, ��ȣ ����� �־����� �� ����� ���� �� �ִ� ���ӵ� ������ ã�� ���̴�.
	���� ��ȣ ��ķ� 2�� �̻��� ���ӵ� �������� ������� �� �ִ�.

	���� ��� (-2, 5, -3, 1)�� (-1, 5, -4,2) �� ���� ��ȣ ����� �����.

	�־��� ��ȣ ����� ���� �� �ִ� ���ӵ� ������ ã�ƶ�.
	�� �� ��� ������ -10 �̻�, 10 ���� �̴�.

�Է�
	ù ° �ٿ� ���ӵ� ������ ������ n(1<=n<=10) �� �Է� �ް�
	�� ° �ٿ� n(n+1)/2 ���� ���ڸ� �Է� �޴´�. �� ���ڴ� ���ӵ� ������ �����Ǵ� ���ڵ��̴�.

���
	���ӵ� ���� �� ���� ����Ѵ�.

	���� ���ӵ� ������ 2�� �̻��� ���, �ƹ��ų� ����ص� �ȴ�.
	��, ��� ������ -10 �̻� 10 �����̴�.
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<char>> signVec;
vector<int> iVec;

bool Check(int idx)
{
	int sum = 0;
	for (int i = idx; i >= 0; --i)
	{
		sum += iVec[i];
		char curSign = sum == 0 ? '0' : sum > 0 ? '+' : '-';
		if (signVec[i][idx] != curSign)
			return false;
	}
	return true;
}

void GetAnswer(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < n; ++i)
			cout << iVec[i] << " ";
		exit(0);
	}

	int start, end;
	if (signVec[cnt][cnt] == '-')
		start = -10, end = -1;
	else if (signVec[cnt][cnt] == '+')
		start = 1, end = 10;
	else
		start = 0, end = 0;

	for (int i = start; i <= end; ++i)
	{
		iVec[cnt] = i;
		if (Check(cnt))
			GetAnswer(cnt + 1);
	}
}

int main()
{
	cin >> n;
	iVec.resize(n);
	signVec.resize(n);

	for (int i = 0; i < n; ++i)
	{
		signVec[i].resize(n);
		for (int j = i; j < n; ++j)
			cin >> signVec[i][j];
	}

	GetAnswer(0);


	return 0;
}