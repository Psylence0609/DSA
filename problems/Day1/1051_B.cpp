#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long l, r;
    scanf("%lld%lld", &l, &r);
    cout << "YES" << endl;
    for (int i = 0; i < int((r - l) / 2 + 1); i++)
        printf("%lld %lld\n", l + i * 2, l + i * 2 + 1);
}