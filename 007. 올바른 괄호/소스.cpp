//����&ť
//bool ����Ÿ���� �� ������ ��������

#include <stdio.h>
#include <stdbool.h>
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt = 0;

    if (s.size() == 0)
        return false;

    for (char c : s)
    {
        if (c == '(')
            ++cnt;
        else if (c == ')')
            --cnt;

        if (cnt < 0)
            return false;
    }
    
    return cnt == 0;
}

int main()
{
	cout << solution(")()(") << endl;
}