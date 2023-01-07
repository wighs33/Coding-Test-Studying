#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//int answer = 0;
map<int, vector<int>> g_graph;
int cnt = 0;

vector<int> visit;
void dfs(int h) {
    //if (answer < h)
    //    answer = h;

    //cout << "h : " << h << endl;
    //for (auto& i : visit)
    //{
    //    cout << i;
    //}
    //cout << endl << endl;

    ++cnt;

    visit[h] = 1;
    for (int i = 0; i < g_graph[h].size(); i++) {
        int y = g_graph[h][i];
        if (visit[y])
        {
            continue;
        }
        //전역변수로 컨테이너에 visit대로 접근하기
        //cout << y << endl;
        dfs(y);
    }
}


int solution(int n, vector<vector<int>> wires) {
    int min_value = 100;

    for (size_t ex = 0; ex  < wires.size(); ex ++)
    {
        map<int, vector<int>> graph;

        for (size_t i = 0; i < wires.size(); i++)
        {
            if (ex!=i)
            {
                graph[wires[i][0]].push_back(wires[i][1]);
                graph[wires[i][1]].push_back(wires[i][0]);
            }
        }

        g_graph = graph;
        visit.clear();
        visit.resize(n + 1);

        dfs(1);

        int val = 2 * cnt - n;
        val = val < 0 ? val * -1 : val;

        min_value = min(min_value, val);
        //cout << "min : " << min_value << endl;

        cnt = 0;
    }

    return min_value;
}

int main()
{
	cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}} ) << endl;
	cout << solution(4, {{1, 2}, {2, 3}, {3, 4}} ) << endl;
	cout << solution(7, {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}} ) << endl;
}