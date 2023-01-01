//스택&큐
//(분모-1)/분자 + 1 이 올림공식이다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

	int length = speeds.size();
	vector<int> days;

	for (size_t i = 0; i < length; i++)
	{
		int day = (99 - progresses[i]) / (float)speeds[i] + 1;
		days.push_back(day);
	}

	int cnt = 1;
	int updateNum = days[0];

	vector<int> Releases;

	for (size_t i = 1; i < length; i++)
	{
		if (updateNum < days[i])
		{
			updateNum = days[i];
			Releases.push_back(cnt);
			cnt = 0;
		}
		++cnt;

	}
	Releases.push_back(cnt);

	return Releases;
}

int main()
{
	for (auto d : solution({ 93, 30, 55 }, { 1,30,5 }))
	{
		cout << d << ' ';
	}

	cout << endl;

	for (auto d : solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 }))
	{
		cout << d << ' ';
	}
}

