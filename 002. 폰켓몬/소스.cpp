//해시
//시간 복잡도 1인 unordered_set를 사용해서 반복없애기
//최대 최소는 max min으로 간편하게 구하자

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