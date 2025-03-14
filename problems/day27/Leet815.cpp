#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int dijkstra(vector<pair<int, int>> graph[], int src, int target)
{
    int V = 1000000;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    // printf("Vertex\t Distance\tPath\n");
    for (int i = 0; i < V; ++i)
    {
        if (i == target)
            return dist[i];
    }
}
int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    vector<pair<int, int>> graph[1000000];

    for (auto &route : routes)
    {
        for (int i = 0; i < route.size() - 1; i++)
            graph[route[i]].push_back({route[i + 1], 1});
        graph[route.front()].push_back({route.back(), 1});
    }
    for (int i = 0; i < 1000000; i++)
    {
        if (graph[i].size() == 0)
            continue;
        else
        {
            cout << "Vertex " << i << " : ";
            for (auto j = graph[i].begin(); j != graph[i].end(); j++)
            {
                cout << (*j).first << " ";
            }
        }
    }
    return dijkstra(graph, source, target);
}

int main()
{
    vector<vector<int>> routes = {{1, 2, 7}, {3, 6, 7}};
    int source = 1, target = 6;
    cout << numBusesToDestination(routes, source, target) << endl;
}