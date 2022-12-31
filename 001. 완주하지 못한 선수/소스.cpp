//해시
// includes                     포함여부
// set_difference           차집합
// set_intersection         교집합     
// set_union                    합집합
// 외우자!

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    vector<string> answer;

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), back_inserter(answer));

    return answer[0];
}

int main()
{
    cout << solution({ "leo", "kiki", "eden" }, { "eden", "kiki" }) << endl;
}