#include <bits/stdc++.h>
using namespace std;

int main()
{
    string ans;
    int n;
    cin >> n;
    while (n)
    {
        int rem = n % 26;
        if (rem == 0)
        {
            ans += 'Z';
            n = n / 26 - 1;
        }
        else
        {
            ans += (rem - 1 + 'A');
            n /= 26;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}