//��
//�̷������ϸ� �ش� ���ͷ����͸� ������ �� ����.
//�ּ� �ִ븦 �䱸�� �� ���ĺ��� ��������
//���Ĺ����� �켱����ť �Ǵ� multiset�� �������
//priority_queue<�ڷ���, �����̳�, ���Լ�>

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