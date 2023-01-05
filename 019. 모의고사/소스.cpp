#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> mans_loop = { { 1,2,3,4,5 }, { 2,1,2,3,2,4,2,5 }, { 3,3,1,1,2,2,4,4,5,5 } };

    map<int, vector<int>, greater<int>> score_man;

    for (int man = 0; man < 3; ++man)
    {
        int score = 0;
        for (size_t i = 0; i < answers.size(); ++i)
        {
            if (mans_loop[man][i % mans_loop[man].size()] == answers[i])
            {
                ++score;
            }
        }
        cout << "score: " << score << endl;
        score_man[score].push_back(man);
    }

    vector<int> scores;
    for (auto man : score_man.begin()->second)
    {
        scores.push_back(man + 1);
    }
    return scores;
}

int main()
{
    for (auto d : solution({ 1,2,3,4,5 }))
    {
        cout << d << ' ';
    }
    cout << endl;

    for (auto d : solution({ 1,3,2,4,2 }))
    {
        cout << d << ' ';
    }
    cout << endl;

    for (auto d : solution({ 3, 3, 1, 1, 1, 1, 2, 3, 4, 5 }))
    {
        cout << d << ' ';
    }
}