#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    vector<bool> used(V);
    vector<int> d(V), p(V); // d is to print levels of vertices

    q.push(0);
    used[0] = true;
    p[0] = -1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : graph[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }

    for (int i : d) // Prints levels of vertices
        cout << i;
    cout << endl;
    int u;
    cin >> u;
    cout << endl;

    // Prints shorted path to vertex u
    if (!used[u])
    {
        cout << "No path!";
    }
    else
    {
        vector<int> path;
        for (int v = u; v != -1; v = p[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int v : path)
            cout << v << " ";
    }
}