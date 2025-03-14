#include <bits/stdc++.h>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;
int *parent, *rnk;
//DSU begin
int find(int u)
{
    if (u == parent[u])
        return parent[u];
    return parent[u] = find(parent[u]);
}

void DisjointSets(int V)
{
    parent = new int[V + 1];
    rnk = new int[V + 1];
    for (int i = 0; i <= V; i++)
    {
        rnk[i] = 0;
        parent[i] = i;
    }
}
void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}
//DSU end
int krushalMST(vector<pair<int, iPair>> edges, int V, int E)
{
    int mst_wt = 0;
    sort(edges.begin(), edges.end());
    DisjointSets(V);
    int num = 0;
    for (auto it = edges.begin(); it != edges.end() && num != V - 1; it++) //vector<pair<int,iPair>> it
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;
            mst_wt += it->first;
            merge(set_u, set_v);
            num++;
        }
    }
    return mst_wt;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, iPair>> edges;

    for (int i = 0; i < E; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({z, {x, y}});
    }
    cout << "Edges of MST:" << endl;
    int mst_wt = krushalMST(edges, V, E);

    cout << "Weight of MST is: " << mst_wt;
}