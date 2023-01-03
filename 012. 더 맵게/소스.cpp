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
	priority_queue<int, vector<int>, greater<int>> scov_queue(scoville.begin(), scoville.end());

	for (size_t cnt = 0; ; cnt++)
	{
		int first_min = scov_queue.top();
		if (first_min >= K)
			return cnt;

		if (scov_queue.size() == 1)
			return -1;

		scov_queue.pop();

		scov_queue.push(first_min + scov_queue.top() * 2);
		scov_queue.pop();
	}
}

int main()
{
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7) << endl;
}