#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        string str_a = to_string(a);
        string str_b = to_string(b);

        return str_a + str_b > str_b + str_a;
        //조건에 맞으면 앞에 둔다.
        });

    string answer = "";
    for (auto& s : numbers)
    {
        answer += to_string(s);
    }

    if (answer[0] == '0')
        return "0";

    return answer;
}

int main()
{
    cout << solution({ 6, 10, 2 }) << endl;
}