//스택&큐
//항상 수도코드부터 작성하기
//반복문에서 결과값이 계산 가능한 시점에 리턴하기

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int weight_in_bridge = 0;
	queue<pair<int, int>> bridge;
	int seconds = 0;

	for (size_t i = 0; ;)
	{
		if (weight >= weight_in_bridge + truck_weights[i])
		{
			bridge.push(make_pair(truck_weights[i], seconds));
			weight_in_bridge += truck_weights[i];
			++i;
		}

		if (i >= truck_weights.size())
		{
			return bridge_length + 1 + seconds;
		}
		else
		{
			++seconds;
			if (bridge.front().second + bridge_length == seconds)
			{
				weight_in_bridge -= bridge.front().first;
				bridge.pop();
			}
		}
	}
}

int main()
{
	cout << solution(2, 10, { 7,4,5,6 }) << endl;
	cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
	cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
}