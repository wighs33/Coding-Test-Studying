//힙
//우선순위 큐에서 값이 큰게 우선순위가 더 작기 때문에 비교함수를 반대로 해야한다.
//공회전이 많더라도 초마다 나눠서 푸는 것이 쉽다.

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int total_time = 0;
    int work_time = 0;
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
        }); // 소요시간으로 우선 배열

    while (true) {
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= total_time) {
                total_time += jobs[i][1];
                work_time += total_time - jobs[i][0];
                if (jobs.size() == 1)
                    return work_time / size;
                jobs.erase(jobs.begin() + i);
                break;
            }

            if (i == jobs.size() - 1) total_time++;
        }
    }
}

int main()
{
	cout << solution({ { 0,3 }, { 1,9 }, { 2,6 } }) << endl;
	cout << solution({ {0, 5} ,{2, 10},{10000, 2} }) << endl;
}