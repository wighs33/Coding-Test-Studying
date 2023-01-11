#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (size_t floor_index = 1; floor_index < triangle.size(); ++floor_index)
    {
        triangle[floor_index][0] = triangle[floor_index - 1][0] + triangle[floor_index][0];

        for (size_t j = 0; j < triangle[floor_index - 1].size() - 1; ++j)
            triangle[floor_index][j + 1] = max(triangle[floor_index - 1][j], triangle[floor_index - 1][j + 1]) + triangle[floor_index][j + 1];

        triangle[floor_index][floor_index] = triangle[floor_index - 1][floor_index - 1] + triangle[floor_index][floor_index];
    }

    int max_num = 0;
    for (int d : triangle[triangle.size() - 1])
    {
        max_num = max(max_num, d);
    }

    //for (auto v : triangle)
    //{
    //    for (int d : v)
    //        cout << d << ' ';
    //    cout << endl;
    //}

    return max_num;
}

int main()
{
    cout << solution({ {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} }) << endl;
}