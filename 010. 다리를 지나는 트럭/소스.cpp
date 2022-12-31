//스택&큐
//항상 수도코드부터 작성하기

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int weight_in_bridge = 0;
	queue<int> bridge;
	int second = 0;
	for (size_t i = 0; ;)
	{
		if (i < truck_weights.size())
		{
			weight_in_bridge += truck_weights[i];
			if (weight < weight_in_bridge)
			{
				weight_in_bridge -= truck_weights[i];
				bridge.push(0);
			}
			else
			{
				bridge.push(truck_weights[i]);
				++i;
			}
		}

		if (bridge.size() == bridge_length)
		{
			weight_in_bridge -= bridge.front();
			bridge.pop();
			++second;
		}
		if (i == truck_weights.size())
			return second + bridge.size() + bridge_length;
	}
}

int main()
{
	cout << solution(100, 100, { 10,10,10,10,10,10,10,10,10,10 }) << endl;
}