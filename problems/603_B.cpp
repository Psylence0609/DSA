#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int P, K;

int pow_mod(int a, int p)
{
    if (p == 0)
        return 1;
    return (long long)a * pow_mod(a, p - 1) % MOD;
}

int main()
{
    cin >> P >> K;
    if (K == 0)
        cout << pow_mod(P, P - 1) << endl;
    else if (K == 1)
        cout << pow_mod(P, P) << endl;
    else
    {
        int ord = 1, cur = K;
        for (; cur != 1; ord++)
            cur = (long long)cur * K % P;
        cout << pow_mod(P, (P - 1) / ord) << endl;
    }
}