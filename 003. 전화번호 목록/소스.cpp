//해시
// 정렬했을 때 인접원소만 비교해도 되는 지부터 생각하자
// substr(start, end) 스트링의 구간추출

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }
    return true;
}

int main()
{
    cout << solution({ "119", "97674223", "1195524421" }) << '\n';
    cout << solution({ "123","456","789" }) << '\n';
    cout << solution({ "12","123","1235","567","88" }) << '\n';
}