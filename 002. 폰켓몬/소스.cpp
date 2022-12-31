//�ؽ�
//�ð� ���⵵ 1�� unordered_set�� ����ؼ� �ݺ����ֱ�
//�ִ� �ּҴ� max min���� �����ϰ� ������

#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());

    return min(nums.size() / 2, s.size());
}

int main()
{
    cout << solution({ 3,1,2,3 }) << '\n';
    cout << solution({ 3,3,3,2,2,4 }) << '\n';
    cout << solution({ 3,3,3,2,2,2 }) << '\n';
}