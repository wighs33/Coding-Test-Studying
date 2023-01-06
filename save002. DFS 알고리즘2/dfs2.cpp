#include <iostream>
#include <string>
#include <vector>
using namespace std;

// index 0�� ������� �������� �迭�� �ϳ� �� �߰�
bool visited[9];
vector<int> graph[9];

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < graph[x].size(); i++) // ������ ��� �����ŭ Ž��
    {
        int y = graph[x][i];
        if (!visited[y]) // �湮���� �ʾ����� �� visited�� False�� �� not�� ���ָ� True�� �ǹǷ� �Ʒ� dfs ����
            dfs(y); // ��������� �湮
    }
}

int main(void)
{
    /* �� �׷����� �����ϰ� ���� */
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs(1);
}