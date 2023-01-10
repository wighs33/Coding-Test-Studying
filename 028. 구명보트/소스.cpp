#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	//우선 정렬
	sort(people.begin(), people.end());

	int i = 0;
	int score = 0;
	for (size_t j = people.size() - 1; ; --j)
	{
		//cout << i << ' ' << j << endl;

		if (i == j) return ++score;
		if (i > j) return score;

		++score;
		if (people[i] + people[j] > limit) continue;

		++i;
	}
}

int main()
{
	cout << solution({ 10, 30, 50, 60, 70, 80, 90, 100, 110, 120 }, 100) << endl;
	cout << solution({ 70, 50, 80, 50 }, 100) << endl;
	cout << solution({ 70, 80, 50 }, 100) << endl;
}