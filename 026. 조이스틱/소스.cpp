#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int total_alphabet_number = 0;
	for (auto& c : name)
	{
		total_alphabet_number += min(c - 'A', 'Z' - c + 1);
	}

	cout << "total : "<<total_alphabet_number << endl;

	int max_a_cnt = 0;
	int a_cnt = 0;
	int cnt_before_max = 0;
	for (size_t i = 1; i < name.size(); i++)
	{
		if (name[i] == 'A')
		{
			++a_cnt;
			continue;
		}

		if (max_a_cnt < a_cnt)
		{
			max_a_cnt = a_cnt;
			cnt_before_max = i - max_a_cnt - 1;
		}
		a_cnt = 0;
	}
	if (max_a_cnt < a_cnt)
	{
		max_a_cnt = a_cnt;
		cnt_before_max = name.size() - max_a_cnt - 1;
	}
	if (max_a_cnt == name.size() - 1 && name[0]=='A') return 0;

	cout << "cnt_before_max : " << cnt_before_max << endl;
	cout << "max_a_cnt : " << max_a_cnt << endl;

	auto pos = find_if(name.rbegin(), name.rend(), [](char a) {return a != 'A'; });
	int behind_a_cnt = distance(name.rbegin(), pos);

	auto pos2 = find_if(name.begin(), name.end(), [](char a) {return a != 'A'; });
	int front_a_cnt = distance(name.begin(), pos2);

	int way1 = min(name.size() - 1 - behind_a_cnt, name.size() - front_a_cnt);

	cout << "behind_a_cnt : " << behind_a_cnt << endl;

	if (max_a_cnt == 0)
	{
		return total_alphabet_number + name.size() - 1;
	}

	int way2 = cnt_before_max + name.size() - max_a_cnt - 1;
	int way3 = 2 * name.size() - 2 - 2 * max_a_cnt - cnt_before_max;
	cout << way1 << ' ' << way2 << ' ' << way3 << endl;

	return total_alphabet_number + min(min(way1, way2), way3);
}

int main()
{
	cout << solution("AAAAABBAAAAAAABAAA") << endl;
}