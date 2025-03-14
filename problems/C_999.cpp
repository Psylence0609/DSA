#include <bits/stdc++.h>

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> cnt(26);
    for (auto c : s)
        ++cnt[c - 'a'];

    int pos = 26;
    for (int i = 0; i < 26; ++i)
    {
        if (k >= cnt[i])
        {
            k -= cnt[i];
        }
        else
        {
            pos = i;
            break;
        }
    }

    string ans;
    int rem = k;
    for (auto c : s)
    {
        int cur = c - 'a';
        if (cur > pos || (cur == pos && rem == 0))
        {
            ans += c;
        }
        else if (cur == pos)
        {
            --rem;
        }
    }

    cout << ans << endl;

    return 0;
}