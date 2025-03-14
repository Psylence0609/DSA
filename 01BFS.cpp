#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> graph[V];
    for (int i = 0; i < E; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }

    vector<int> dist(V, INT_MAX);
    deque<int> q;
    dist[0] = 0;
    q.push_back(0);

    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (auto i = graph[v].begin(); i < graph[v].end(); i++)
        {
            if (dist[(*i).first] > dist[v] + (*i).second)
            {
                dist[(*i).first] = dist[v] + (*i).second;
                if ((*i).second == 0)
                    q.push_front((*i).first);
                else
                    q.push_back((*i).first);
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
}