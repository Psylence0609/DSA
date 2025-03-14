#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2)
{
    float f1 = p1.second / p1.first.second;
    float f2 = p2.second / p2.first.second;
    return f1 > f2;
}

int main()
{

    int n, v;
    cin >> n >> v;
    vector<pair<pair<int, int>, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first.second >> a[i].second;
        a[i].first.first = i + 1;
    }
    sort(a.begin(), a.end(), compare);
    int remaining = v;
    int total = 0;
    vector<int> boat_num;
    for (auto it : a)
    {
        if (it.first.second > remaining)
            continue;
        total += it.second;
        remaining -= it.first.second;
        boat_num.push_back(it.first.first);
    }
    cout << total << endl;
    for (auto it : boat_num)
    {
        cout << it << " ";
    }
}