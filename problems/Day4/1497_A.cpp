#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        // for (auto it : a)
        //     cout << it << " ";
        // cout << endl;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                int temp = a[i];
                a.erase(a.begin() + i);
                a.push_back(temp);
                i--;
                n--;
            }
            // for (auto it : a)
            //     cout << it << " ";
            // cout << endl;
        }
        for (auto it : a)
            cout << it << " ";
    }
}
