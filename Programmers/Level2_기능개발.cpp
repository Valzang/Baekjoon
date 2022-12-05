#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
���� ����
    ���α׷��ӽ� �������� ��� ���� �۾��� ���� ���Դϴ�. �� ����� ������ 100%�� �� ���񽺿� �ݿ��� �� �ֽ��ϴ�.
    ��, �� ����� ���߼ӵ��� ��� �ٸ��� ������ �ڿ� �ִ� ����� �տ� �ִ� ��ɺ��� ���� ���ߵ� �� �ְ�,
    �̶� �ڿ� �ִ� ����� �տ� �ִ� ����� ������ �� �Բ� �����˴ϴ�.

    ���� �����Ǿ�� �ϴ� ������� �۾��� ������ ���� ���� �迭 progresses��
    �� �۾��� ���� �ӵ��� ���� ���� �迭 speeds�� �־��� ��
    �� �������� �� ���� ����� �����Ǵ����� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���� ����
    �۾��� ����(progresses, speeds�迭�� ����)�� 100�� �����Դϴ�.
    �۾� ������ 100 �̸��� �ڿ����Դϴ�.
    �۾� �ӵ��� 100 ������ �ڿ����Դϴ�.
    ������ �Ϸ翡 �� ���� �� �� ������, �Ϸ��� ���� �̷�����ٰ� �����մϴ�. ���� ��� �������� 95%�� �۾��� ���� �ӵ��� �Ϸ翡 4%��� ������ 2�� �ڿ� �̷�����ϴ�.

progresses	                speeds	                return
[93, 30, 55]	            [1, 30, 5]	            [2, 1]
[95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	    [1, 3, 2]

*/


vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    vector<int> usedDay;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int leftProgress = 100 - progresses[i];
        int day = leftProgress % speeds[i] != 0 ? leftProgress / speeds[i] + 1 : leftProgress / speeds[i];
        usedDay.push_back(day);
    }

    int last = 0;
    if (usedDay.size() != 0)
	{
		answer.push_back(1);
        last = usedDay[0];
	}

    
    for (int j = 1; j < usedDay.size(); ++j)
    {
        if (usedDay[j] > last)
        {
            last = usedDay[j];
            answer.push_back(1);
        }
        else
            answer.back() += 1;
    }
        
    return answer;
}

int main()
{
    vector<int> progresses = { 3, 1, 2, 1, 4, 1 };  
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> results = solution(progresses, speeds);

    for (int i = 0; i < results.size(); ++i)
    {
        cout <<  results[i] << " ";
    }
    cout << '\n';
    



    return 0;
}