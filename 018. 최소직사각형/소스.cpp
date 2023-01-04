#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    for (size_t i = 0; i < sizes.size(); i++)
    {
        sort(sizes[i].begin(), sizes[i].end());
    }

    int max_row = max_element(sizes.begin(), sizes.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; })->at(1);
    int max_column = max_element(sizes.begin(), sizes.end())->at(0);
    return max_row * max_column;
}

int main()
{
    cout << solution({ {60, 50}, {30, 70}, {60, 30}, {80, 40} }) << endl;
    cout << solution({{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}} ) << endl;
    cout << solution({{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}} ) << endl;
}