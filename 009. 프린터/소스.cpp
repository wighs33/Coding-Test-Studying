//����&ť
//Ư�� ��ġ�� �ʿ��� �� �ε��� �����̳� �ϳ� ���� ����ų� �� Ÿ������ �ϴ� �����̳� �����
//�ִ��� ������ �ƴ϶� max_element ����ϱ�

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

	queue<int> indexes;

	//ť�� ����ֱ�
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
