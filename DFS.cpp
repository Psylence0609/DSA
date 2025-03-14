#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int s)
{
    visited[s] = true;
    cout << s << endl;
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (!visited[graph[s][i]])
            dfs(graph, visited, graph[s][i]);
    }
}

int dfs_disconnected(vector<vector<int>> &graph, vector<bool> &visited, int V)
{
    int connected = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
            connected++;
        }
    }
    return connected;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    vector<bool> visited(V, 0);
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(graph, visited, 0);
    cout << dfs_disconnected(graph, visited, V);
}