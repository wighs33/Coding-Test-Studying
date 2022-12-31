//스택&큐
//unique는 정렬하지 않아도 쓸수 있다
//unique는 사용되는 원소를 앞에두고 남은 부분중 제일 앞의 이터레이터를 리턴한다.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
}

int main()
{
    for (auto d : solution({ 1, 1, 3, 3, 0, 1, 1 }))
    {
        cout << d << ' ';
    }
}