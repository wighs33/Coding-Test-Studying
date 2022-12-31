//����&ť
//Ư�� ��ġ�� �ʿ��� �� �ε��� �����̳� �ϳ� ���� ����ų� �� Ÿ������ �ϴ� �����̳� �����

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {

	queue<int> prior;
	queue<char> loc;

	//ť�� ����ֱ�
	for (auto d : priorities)
		prior.push(d);

	//��ġ ť
	for (size_t i = 0; i < priorities.size(); i++)
	{
		if (location == i)
			loc.push('O');
		else
			loc.push('X');
	}

	//�����ϱ�
	sort(priorities.rbegin(), priorities.rend());

	int cnt = 0;

	while (true)
	{
		//ť ���� ���� �ƽ��ѹ����� Ȯ��
		if (prior.front() == priorities[0])
		{
			if (loc.front() == 'X')
			{
				prior.pop();
				loc.pop();
				++cnt;
				//�ƽ��ѹ���ü
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
