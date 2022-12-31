//해시
// 필요하다면 map두개 만들어서 연관 짓자 복잡함을 줄일 수 있다.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<pair<int, int>>> hash_map;
	map<int, string, greater<int>> hash_map2;

	for (size_t i = 0; i < genres.size(); i++)
	{
		hash_map[genres[i]].push_back(make_pair(i, plays[i]));
	}

	for (auto& keyvalue : hash_map)
	{
		sort(keyvalue.second.begin(), keyvalue.second.end(), [](pair<int, int> a, pair<int, int> b) {
			if (a.second == b.second)
				return a.first < b.first;
			else
				return a.second > b.second;
			});

		int totalplay = 0;

		for (auto p : keyvalue.second)
		{
			totalplay += p.second;
		}

		hash_map2[totalplay] = keyvalue.first;
	}

	for (auto keyvalue : hash_map2)
	{
		answer.push_back(hash_map[keyvalue.second][0].first);
		if (hash_map[keyvalue.second].size() > 1)
			answer.push_back(hash_map[keyvalue.second][1].first);
	}

    return answer;
}

int main()
{
    for(auto d : solution({ "classic", "pop", "classic", "classic", "pop", "head"}, {500, 600, 150, 800, 2500, 100}))
		cout << d << '\n';
}