#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/*

��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

������ : 119
���ؿ� : 97 674 223
������ : 11 9552 4421
��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, 
� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
    phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.   
    �� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
    ���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.

����� ����
phone_book	                         return
["119", "97674223", "1195524421"]	false
["123","456","789"]	                true
["12","123","1235","567","88"]	    false

*/

// �ð��ʰ� �� ��Ȯ�� ����

bool compare(string a, string b)
{
    return a.size() < b.size();
}

bool find(string a, string b, int& matchCount, int& stringSize)
{
    int matchcnt = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        // �ٸ�
        if (a[i] != b[i])
        {
            stringSize = b.size();
            return false;
        }
        ++matchcnt;
    }
    // ������
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

    map<int, vector<string>> map;

    int curStringSize = 0;
    int matchCount = 0;
    sort(phone_book.begin(), phone_book.end(), compare);

    for (int i = 0; i < phone_book.size(); ++i)
    {
        for (int j = 0; j < phone_book.size(); ++j)
        {
            if (phone_book[i].size() == phone_book[j].size())
                continue;

            if (find(phone_book[i], phone_book[j], matchCount, curStringSize))
                return false;
        }
    }
    return answer;
}

int main()
{
    vector<string> phone_book = { "12", "123", "1235", "567", "88" };

    cout << "���� : " << solution(phone_book) << '\n';


    return 0;
}