#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<pair<int, int>>> mp;
unordered_map<string, int> cst;
void solve()
{
    for (auto p : mp)
    {
        auto v = p.second;
        string org = p.first;
        sort(v.begin(), v.end());
        int curr = v[0].first;

        int cost = 0;
        while (true)
        {
            int c = 0;
            for (auto x : v)
            {
                if (x.first <= curr && x.second > curr)
                    c++;
            }
            if (c == 0)
                break;
            else if (c == 1)
                cost += 100;
            else if (c == 2)
                cost += 150;
            else if (c == 3)
                cost += 200;
            else
                cost += 200 + (c - 3) * 20;
            curr++;
            // cout << cost;
        }
        cst[org] = cost;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string temp = "";
        int c = 0, st, e;
        string org;

        for (auto ch : s)
        {
            if (c == 0 && ch == ',')
            {
                org = temp;
                c++;
                temp = "";
            }
            else if (c == 1 && ch == ',')
            {
                st = stoi(temp);
                c++;
                temp = "";
            }
            else
                temp += ch;
        }
        e = stoi(temp);
        mp[org].push_back({st, e});
    }
    solve();
    for (auto p : cst)
    {
        cout << p.first << " bill: " << p.second << endl;
    }
}