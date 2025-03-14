/**
#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &respect, int s)
{
    visited[s] = true;
    int r = 0;
    if (respect[s] == 1)
    {
        cout << s + 1 << " ";
        r++;
    }
    for (int i = 0; i < graph[s].size(); i++)
    {
        if (!visited[graph[s][i]])
            r += dfs(graph, visited, respect, graph[s][i]);
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, 0);
    vector<int> respect;
    int parent;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        respect.push_back(y);
        if (x != -1)
        {
            graph[i].push_back(x - 1);
            graph[x - 1].push_back(i);
        }
        else
            parent = i;
    }

    int r = dfs(graph, visited, respect, parent);
    if (!r)
        cout << -1;
}
**/
// This solution (above) is not exactly correct

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
ll parent[100005], rmv[100005], respect[100005];
int main()
{
    ll m, n, i, j, k;
    cin >> n;
    fr1(i, n)
    {
        cin >> parent[i] >> respect[i];
        rmv[i] = 1;
    }

    fr1(i, n)
    {
        if (respect[i] == 0)
        {
            rmv[i] = 0;
            rmv[parent[i]] = 0;
        }
    }
    //cout<<rmv[-1]<<endl;

    ll ans = 0, cnt = 1;

    fr1(i, n)
    {
        if (rmv[i] == 1)
            cout << i << " ", cnt = 0;
    }

    if (cnt)
        cout << "-1" << endl;
}