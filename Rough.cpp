#include <bits/stdc++.h>
using namespace std;

int dijkstra(vector<vector<int>> graph, int V, int src, int end)
{
    priority_queue<pair<int, int>> pq;
    vector<bool> visited(V);
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto v : graph[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end] < INT_MAX ? dist[end] : 0;
}

bool compare(string a, string b)
{
    if (a.size() != b.size())
        return false;
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    if (count == 1)
        return true;

    return false;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    bool check = false;
    int pos = wordList.size();
    int end_pos = -1;

    for (int i = 0; i < wordList.size(); i++)
    {
        if (wordList[i] == beginWord)
        {
            check = true;
            pos = i;
        }
        if (wordList[i] == endWord)
        {
            end_pos = i;
            // cout << "check";
        }
    }
    if (end_pos == -1)
        return 0;
    if (!check)
        wordList.push_back(beginWord);
    vector<vector<int>> graph(wordList.size());
    // cout << "check";
    for (int i = 0; i < wordList.size(); i++)
    {
        for (int j = 0; j < wordList.size(); j++)
        {
            if (i == j)
                continue;
            if (compare(wordList[i], wordList[j]))
            {
                cout << i << " " << j << endl;
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    if (graph[pos].size() == 0)
        return 0;
    int ans = dijkstra(graph, wordList.size(), pos, end_pos);
    if (ans == 0)
        return 0;
    return ans + 1;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "tog", "cog"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    // cout << compare("hot", "dog");
    return 0;
}