#include <bits/stdc++.h>
using namespace std;

pair<int, int> getComma(string s, map<string, set<int>> &mp)
{
    string func;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            count++;
            func = "";
        }
        else if (s[i] == '(')
        {
            auto c = getComma(s.substr(i + 1), mp);
            mp[func].insert(c.first);
            i += c.second + 1;
        }
        else if (s[i] == ')')
        {
            return {count, i};
        }
        else
        {
            func += s[i];
        }
    }
    return {0, 0};
}

int main()
{
    string s;
    cin >> s;
    string func;
    map<string, set<int>> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            auto c = getComma(s.substr(i + 1), mp);
            mp[func].insert(c.first);
            break;
        }
        else
            func.push_back(s[i]);
    }
    int ans = 0;
    for (auto i : mp)
    {
        cout << i.first << ": ";
        ans += i.second.size();
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    }
    cout << ans << endl;
}
//  fun1(fun2(a,b),c,fun2(a),fun3(c,d))