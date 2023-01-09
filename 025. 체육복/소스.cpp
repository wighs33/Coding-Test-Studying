#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	vector<int> lost2;
	vector<int> reserve2;
	set_difference(lost.begin(), lost.end(), reserve.begin(), reserve.end(), back_inserter(lost2));
	set_difference(reserve.begin(), reserve.end(), lost.begin(), lost.end(), back_inserter(reserve2));

	int cover = lost2.size();
	for (auto& d : lost2)
	{
		auto give = find_if(reserve2.begin(), reserve2.end(), [&d](int a) {return (a == d - 1) || (a == d + 1); });
		if (give != reserve2.end())
		{
			reserve2.erase(give);
			--cover;
			continue;
		}
	}

	return n - cover;
}

int main()
{
	cout << solution(5, { 1,2,4 }, { 2,3,4,5 }) << endl;
}