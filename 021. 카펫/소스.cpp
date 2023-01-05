#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
	for (int i = 1; i * i <= yellow; i++)
    {
        if (yellow % i == 0)
        {
           int w = yellow/i + 2;
           int h = i + 2;

           if (w * h == brown + yellow)
               return { w,h };
        }
    }
}

int main()
{
    for (auto d : solution(10, 2))
    {
        cout << d << ' ';
    }
    cout << endl;

    for (auto d : solution(8, 1))
    {
        cout << d << ' ';
    }
    cout << endl;
    for (auto d : solution(24, 24))
    {
        cout << d << ' ';
    }
}