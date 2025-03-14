#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
//Note that each edge is taken as an undirected edge
//To make into directed graph simply remove the edges
void BellmanFord(vector<vector<int>> graph, int V, int E, int src)
{
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i < V; i++)
    {
        for (int j = 0; j < 2 * E; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int w = graph[j][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
    //Detecting negative cycles
    for (int j = 0; j < 2 * E; j++)
    {
        int u = graph[j][0];
        int v = graph[j][1];
        int w = graph[j][2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Graph contains negative w cycle";
            return;
        }
    }

    //Printing
    for (int i = 0; i < V; i++)
    {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(2 * E, vector<int>(3));
    for (int i = 0; i < 2 * E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph[i][0] = s;
        graph[i][1] = d;
        graph[i][2] = w;
        graph[++i][0] = d;
        graph[i][1] = s;
        graph[i][2] = w;
    }

    BellmanFord(graph, V, E, 0);
}
