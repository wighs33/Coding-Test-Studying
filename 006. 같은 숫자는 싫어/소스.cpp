//����&ť
//unique�� �������� �ʾƵ� ���� �ִ�
//unique�� ���Ǵ� ���Ҹ� �տ��ΰ� ���� �κ��� ���� ���� ���ͷ����͸� �����Ѵ�.

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