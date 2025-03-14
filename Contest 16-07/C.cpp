#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k;
    int n, m;
    string s;
    set<string> st;
    cin >> n >> m;

    for (i = 0; i < n + m; i++)
    {
        cin >> s;
        st.insert(s);
    }
    if (n + m - st.size() > 0)
    {
        int extra = n + m - st.size();
        // cout << extra << endl;
        n = n - extra;
        m = m - extra;
        if (extra % 2 == 1)
        {
            n += extra / 2 + 1;
            m += extra / 2;
        }
        else
        {
            n += extra / 2;
            m += extra / 2;
        }
    }
    if (n > m)
        cout << "YES";
    else
        cout << "NO";
}