//힙
//sstream을 쓰면 스트링 안 문자와 숫자를 간단하게 분리할 수 있다.

#include <string>
#include <vector>
#include <set>
#include <sstream>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> values;
    char order_code;
    int value;

    for (string& str : operations)
    {
        stringstream ss(str);
        ss >> order_code;
        ss >> value;

        if (order_code == 'I')
            values.insert(value);
        else
        {
            if (values.empty()) continue;

            if (value == 1)
                values.erase(--values.end());
            else
                values.erase(values.begin());
        }
    }

    if (values.empty())
        return { 0,0 };
    else
        return{ *--values.end(), *values.begin() };
}

int main()
{
    for (auto d : solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" }))
    {
        cout << d << ' ';
    }
}