#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

void printPath(vector<int> parent, int i)
{
    if (parent[i] == -1)
        return;
    printPath(parent, parent[i]);
    printf("%d ", i);
}

void dijkstra(vector<pair<int, int>> graph[], int V, int E, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    vector<int> parent(V);
    parent[0] = -1;
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
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex\t Distance\tPath\n");
    for (int i = 1; i < V; ++i)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> graph[V];
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s].push_back(make_pair(d, w));
        graph[d].push_back(make_pair(s, w));
    }

    dijkstra(graph, V, E, 0);
}