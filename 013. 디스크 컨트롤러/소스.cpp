//힙
//우선순위 큐에서 값이 큰게 우선순위가 더 작기 때문에 비교함수를 반대로 해야한다.
//공회전이 많더라도 초마다 나눠서 푸는 것이 쉽다.

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
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0; // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

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