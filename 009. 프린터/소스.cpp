//스택&큐
//특정 위치가 필요할 때 인덱스 컨테이너 하나 따로 만들거나 페어를 타입으로 하는 컨테이너 만들기
//최댓값은 정렬이 아니라 max_element 사용하기

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

	queue<int> indexes;

	//큐에 집어넣기
	for (size_t i = 0; i < priorities.size(); i++)
	{
		indexes.push(i);
	}

	int cnt = 0;

	while (true)
	{
		int front = indexes.front();
		if (priorities[front] == *max_element(priorities.begin(), priorities.end()))
		{
			++cnt;
			priorities[front] = 0;
			if (location == front)
				return cnt;
			indexes.pop();
		}
		else
		{
			indexes.pop();
			indexes.push(front);
		}
	}
}

int main()
{
	cout<<solution({ 1, 1, 9, 1, 1, 1 }, 0);
}
