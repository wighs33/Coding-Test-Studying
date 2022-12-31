//힙
//이레이저하면 해당 이터레이터를 참조할 수 없다.
//최소 최대를 요구할 땐 정렬부터 생각하자
//정렬문제는 우선순위큐 또는 multiset을 사용하자
//priority_queue<자료형, 컨테이너, 비교함수>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> scov_queue(scoville.begin(), scoville.end());

	while (true)
	{
		int first_min = scov_queue.top();
		if (first_min >= K)
			return cnt;

		if (scov_queue.size() == 1)
			return -1;

		scov_queue.pop();

		auto second_min = scov_queue.top();

		scov_queue.pop();

		int mix = first_min + second_min * 2;
		scov_queue.push(mix);

		++cnt;
	}
}

int main()
{
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7) << endl;
}