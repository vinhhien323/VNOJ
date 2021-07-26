#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
using namespace std;
const int N = 2000;
bitset <N+1> visited;
int n,m;
int a,b,h;
int k = 0;
vector <vector<int>> graph;
void DFS(int j)
{
    stack <int> Line;
    Line.push(j);
    visited[j] = true;
    while(!Line.empty())
    {
        h = Line.top();
        Line.pop();
        for(int i : graph[h])
        {
            if(!visited[i])
            {
                Line.push(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    graph.resize(n+1);
    fo(i,1,m)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    fo(i,1,n)
    {
        if(!visited[i])
        {
            DFS(i);
            k++;
        }
    }
    cout << max(0,m-n+k);
    return 0;
}
