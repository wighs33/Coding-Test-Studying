#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int STATIC_K = 0;
int g_k = 0;
vector<vector<int>> g_dungeons;

static int max_cnt = 0;

int play_dungeons(string orders)
{
	for (size_t i = 0; i < orders.size(); i++)
	{
		int now = orders[i] - '0';

		//cout << g_k <<' '<< i << ' '<< g_dungeons[now][0]<< ' '<< g_dungeons[now][1]<< endl;
		if (g_dungeons[now][0] <= g_k)
			g_k -= g_dungeons[now][1];
		else
		{
			return i;
		}
	}
	return orders.size();
}

void mix_func(string mix, int pos, string numbers)
{
	//사이즈까지 모든 조합
	//cout << "mix: " << mix << endl;

	//사이즈가 채워질 때 조합
	if (pos == mix.size())
	{
		g_k = STATIC_K;
		max_cnt = max(max_cnt, play_dungeons(mix));

		//cout << "mix: " << mix << endl;
		//cout << "max: " << max_cnt << endl;
		return;
	}

	for (size_t i = 0; i < numbers.size(); i++)
	{
		string a = numbers;
		string m = mix;
		int p = pos;
		m[p] = a[i];
		a.erase(a.begin() + i);

		mix_func(m, ++p, a);
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	STATIC_K = k;
	g_k = k;
	g_dungeons = dungeons;

	string numbers;
	numbers.resize(dungeons.size());

	for (int i = 0; i < dungeons.size(); i++)
	{
		numbers[i] = i + '0';
	}

	string mix;
	mix.resize(numbers.size());

	mix_func(mix, 0, numbers);

	return 	max_cnt;
}


int main()
{
	cout << solution(100, { {80,20}, {50,40}, {30, 10} }) << '\n';
	cout << solution(40, { {40,20}, {10,10}, {10, 10},{10, 10},{10, 10} }) << '\n';
}