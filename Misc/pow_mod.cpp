#include <bits/stdc++.h>
using namespace std;

// used to find x^n mod m

int pow_mod(int x, int n, int m) // similar to binpow_mod func in binary_exponentiation.cpp
{
    if (n == 0)
        return 1;
    int t = pow_mod(x, (int)floor(n / 2), m);
    if (n % 2 == 0)
        return (int)fmod(t * t, m);
    else
        return (int)fmod(t * t * x, m);
}

int main()
{
    int x, n, m;
    cin >> x >> n >> m;
    int ans = pow_mod(x, n, m);
    cout << ans;
}
// proper sol:
//  if(n==0)
//          return 1%d;
//      if(n==1)
//          return max(abs(x)%d, d-abs(x)%d);
//      long long ans = pow(x, n/2, d)%d;
//      ans = (ans*ans)%d;
//      if(n%2)
//          ans = (ans*x)%d;
//      return ans%d;