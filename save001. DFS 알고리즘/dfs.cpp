#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited(3, false);

void dfs(int cnt, vector<bool> vec)
{
	vector<bool> tmp = vec;
	tmp[cnt] = true;

	for (bool b : tmp)
	{
		cout << b << ' ';
	}
	cout << endl;

	int true_cnt = 0;
	for (size_t i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == false)
			dfs(i, tmp);
		else
			++true_cnt;
	}

	if (true_cnt == tmp.size())
	{
		//�� ��忡 ���� �� �����ڵ�
	}
}

int main()
{
	for (size_t i = 0; i < visited.size(); i++)
	{
		dfs(i, visited);
	}
}