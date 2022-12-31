//��
//�켱���� ť���� ���� ū�� �켱������ �� �۱� ������ ���Լ��� �ݴ�� �ؾ��Ѵ�.
//��ȸ���� ������ �ʸ��� ������ Ǫ�� ���� ����.

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; // ������� �۾��� ����� �ð�
    int time = 0; // ������ �۾��� ����Ǵµ� �ɸ� �ð����� ��
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // �ҿ�ð����� �켱 �迭

    while (!jobs.empty()) {
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if (i == jobs.size() - 1) start++;
        }
    }

    answer = time / size;
    return answer;
}

int main()
{
	cout << solution({ { 0,3 }, { 1,9 }, { 2,6 } }) << endl;
	cout << solution({ {0, 5} ,{2, 10},{10000, 2} }) << endl;
}