#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> times;
    size_t length = prices.size();
    for (size_t i = 0; i < length; ++i)
    {
        int time = 1;
        for (size_t j = i+1; j < length; ++j)
        {
            if (prices[i] > prices[j])
            {
                times.push_back(time);
                break;
            }
            if (j == length - 1)
            {
                times.push_back(time);
                break;
            }
            time += 1;
        }
    }
    times.push_back(0);
    return times;
}

int main()
{
    for (auto d : solution({ 1, 2, 3, 2, 3 }))
    {
        cout << d << ' ';
    }

}