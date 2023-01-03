#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto command : commands)
    {
		vector<int> tmp(array.begin() + command[0] - 1, array.begin() + command[1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[command[2] - 1]);
    }

    return answer;
}

int main()
{
    for (auto d : solution({ 1, 5, 2, 6, 3, 7, 4 }, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}} ))
    {
        cout << d << ' ';
    }
}