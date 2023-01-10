#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> island(101);

    //섬 저장
    for (int i = 0; i < n; i++) {
        island[i] = i;
    }
    // 1. 비용이 적은순으로 정렬
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
        return a[2] < b[2]; });

    function<int(int)> findParent = [&](int idx)  -> int {
        if (island[idx] == idx)
            return idx;
        return island[idx] = findParent(island[idx]);
    };

    for (int i = 0; i < costs.size(); i++) {
        int start = findParent(costs[i][0]);
        int end = findParent(costs[i][1]);
        int cost = costs[i][2];

        //2. cycle이 만들어지지 않으면 다리 추가
        if (start != end) {
            answer += cost;
            island[end] = start;
        }
    }

    return answer;
}

int main()
{
	//cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}} ) << endl;
	cout << solution(5, { {0, 1, 1}, { 3, 4, 1 }, { 1, 2, 2 }, { 2, 3, 4 }}) << endl;


	//7 {{2, 3, 7}, {3, 6, 13}, {3, 5, 23}, {5, 6, 25}, {0, 1, 29}, {1, 5, 34}, {1, 2, 35}, {4, 5, 53}, {0, 4, 75}} 159
	//	5 {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7}} 15
	//	5 {{0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4}} 8
	//	4 {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {1, 3, 2}, {0, 3, 4}} 9
	//	5 {{0, 1, 1}, {3, 1, 1}, {0, 2, 2}, {0, 3, 2}, {0, 4, 100}} 104
	//	6 {{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}} 11
	//	5 {{0, 1, 1}, {2, 3, 1}, {3, 4, 2}, {1, 2, 2}, {0, 4, 100}} 6
	//	5 {{0, 1, 1}, {0, 4, 5}, {2, 4, 1}, {2, 3, 1}, {3, 4, 1}} 8
	//	5 {{0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {0, 4, 4}, {1, 3, 1}} 8
	//	5 {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 3}, {2, 3, 8}, {3, 4, 1}} 7
	//	5 {{0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4}} 8
	//	4 {{0, 1, 1}, {0, 2, 2}, {2, 3, 1}} 4
}