//�ؽ�
//������ �ʿ����� �����Ͱ� ���� �ʿ����� �ľ�����
//�׷�ȭ ���Ѽ� ���н����� �����

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> hash_map;

    for (auto data : clothes)
    {
        ++hash_map[data[1]];
    }

    for (auto keyvalue : hash_map)
    {
		answer *= keyvalue.second + 1;
    }

    return answer-1;
}

int main()
{
    cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}) << '\n';
    cout << solution({{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}} ) << '\n';
}