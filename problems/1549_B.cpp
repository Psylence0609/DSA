#include <bits/stdc++.h>
using namespace std;

int maxans(string enemy, string pawns, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (pawns[i] == '1')
        {
            int pos = i;
            if (enemy[pos] == '0')
            {
                ans++;
                enemy[pos] == '2';
                continue;
            }
            else if (pos - 1 >= 0 && enemy[pos - 1] == '1')
            {
                ans++;
                enemy[pos - 1] = '2';
                continue;
            }
            else if (pos + 1 < n && enemy[pos + 1] == '1')
            {
                ans++;
                enemy[pos + 1] = '2';
                continue;
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string enemy;
        string pawns;
        cin >> enemy;
        cin >> pawns;
        cout << maxans(enemy, pawns, n) << endl;
    }
}