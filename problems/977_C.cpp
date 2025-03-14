#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int num[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    if (k == 0)
    {
        if (num[0] == 1)
            cout << "-1";
        else
            cout << num[0] - 1;
        return 0;
    }
    if (num[k - 1] == num[k])
        cout << "-1";
    else
        cout << num[k - 1];
}