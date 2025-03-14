#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
long long int fact[1000000];
long long int ans[1000000];

int main()
{
    int n;
    cin >> n;
    if (n == 1 || n == 0)
    {
        cout << n;
        return 0;
    }
    ans[0] = 0;
    ans[1] = 1;
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fact[i] = (long long int)fmod(fact[i - 1] * i, mod);
        ans[i] = (long long int)fmod(fact[i] + (long long int)fmod((ans[i - 1] - 1) * i, mod), mod);
    }
    //for (int i = 0; i <= n; i++)
    //    cout << fact[i] << endl;
    cout << ans[n];
}