#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int solution(string word) {
    map<char, int> match;
    match['A'] = 0;
    match['E'] = 1;
    match['I'] = 2;
    match['O'] = 3;
    match['U'] = 4;

    vector<int> key_number = { 781, 156, 31, 6, 1 };

    int answer = 0;
    for (size_t i = 0; i < word.size(); i++)
    {
        answer += key_number[i] * match[word[i]] + 1;
        cout << answer << endl;
    }

    return answer;
}

int main()
{
    //cout << solution("AAAAE") << endl;
    cout << solution("AAAE") << endl;
    //cout << solution("I") << endl;
    //cout << solution("EIO") << endl;
}