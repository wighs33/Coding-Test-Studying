#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<int> To_Search;
int N;

int visit[8];
void dfs(int h){
    if(answer < h)
        answer = h;

    cout << "h : " << h << endl;
    cout << visit[0] << visit[1]<< visit[2]<< endl;

    for(int i=0; i<N; i++){
        if (visit[i])
        {
            continue;
        }
        
        visit[i] = 1;
        //���������� �����̳ʿ� visit��� �����ϱ�
        cout << To_Search[i] << endl;
        dfs(h+1);
        cout <<"��������"<< endl;
        visit[i] = 0;
    }
}

int main()
{
    To_Search = { 0,1,2 };
    N = To_Search.size();

    dfs(0);
}