/*

����
	RGB�Ÿ����� ���� N�� �ִ�. �Ÿ��� �������� ��Ÿ�� �� �ְ�, 1�� ������ N�� ���� ������� �ִ�.
	���� ����, �ʷ�, �Ķ� �� �ϳ��� ������ ĥ�ؾ� �Ѵ�.

	������ ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �־����� ��, �Ʒ� ��Ģ�� �����ϸ鼭 ��� ���� ĥ�ϴ� ����� �ּڰ��� ���غ���.

	- 1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
	- N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
	- i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.
�Է�
	ù° �ٿ� ���� �� N(2 �� N �� 1,000)�� �־�����.
	��° �ٺ��� N���� �ٿ��� �� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� 1�� ������ �� �ٿ� �ϳ��� �־�����.
	���� ĥ�ϴ� ����� 1,000���� �۰ų� ���� �ڿ����̴�.

���
	ù° �ٿ� ��� ���� ĥ�ϴ� ����� �ּڰ��� ����Ѵ�.
*/



#include <iostream>

using namespace std;

int R = 0;
int G = 1;
int B = 2;

int colorCost[1001][3];

int Min(int A, int B, int C = -1)
{
	if(C==-1)
		return A < B ? A : B;
	
	A = A < B ? A : B;
	return A < C ? A : C;
}

int main()
{
	int houseCount;

	cin >> houseCount;

	for (int i = 1; i <= houseCount; ++i)
	{
		cin >> colorCost[i][R] >> colorCost[i][G] >> colorCost[i][B];
		colorCost[i][R] += Min(colorCost[i - 1][G], colorCost[i - 1][B]);
		colorCost[i][G] += Min(colorCost[i - 1][B], colorCost[i - 1][R]);
		colorCost[i][B] += Min(colorCost[i - 1][R], colorCost[i - 1][G]);
	}

	cout << Min(colorCost[houseCount][R], colorCost[houseCount][G], colorCost[houseCount][B]);

	return 0;
}

/*


�ݷ� 1
10
711 572 325
209 187 673
512 930 898
759 85 260
136 226 532
201 3 959
132 607 359
601 775 848
462 776 920
74 807 671

�� 3058

*/