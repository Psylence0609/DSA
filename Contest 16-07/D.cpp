#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    vector<int> temp = b;
    sort(b.begin(), b.end());
    map<int, int> mp;
    for (int i = 0, j = 0; j < m;)
    {
        if (a[i] >= b[j])
        {
            mp[b[j]] = i + 1;
            j++;
        }
        else
            i++;
    }
    for (auto r : temp)
    {
        cout << mp[r] << endl;
    }
    return 0;
}