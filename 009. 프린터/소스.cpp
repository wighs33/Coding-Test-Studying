//스택&큐
//특정 위치가 필요할 때 인덱스 컨테이너 하나 따로 만들거나 페어를 타입으로 하는 컨테이너 만들기

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

	queue<int> prior;
	queue<char> loc;

	//큐에 집어넣기
	for (auto d : priorities)
		prior.push(d);

	//위치 큐
	for (size_t i = 0; i < priorities.size(); i++)
	{
		if (location == i)
			loc.push('O');
		else
			loc.push('X');
	}

	//정렬하기
	sort(priorities.rbegin(), priorities.rend());

	int cnt = 0;

	while (true)
	{
		//큐 제일 앞이 맥스넘버인지 확인
		if (prior.front() == priorities[0])
		{
			if (loc.front() == 'X')
			{
				prior.pop();
				loc.pop();
				++cnt;
				//맥스넘버교체
				priorities.erase(priorities.begin());
			}
			else
				return ++cnt;
		}
		else 
		{
			int tmp = prior.front();
			prior.pop();
			prior.push(tmp);

			int tmp2 = loc.front();
			loc.pop();
			loc.push(tmp2);
		}
	}
}

int main()
{
	cout<<solution({ 1, 1, 9, 1, 1, 1 }, 0);
}
