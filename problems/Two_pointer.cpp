/**
There are N hotels along the beautiful Adriatic coast. Each hotel has its value in Euros.

Sroljo has won M Euros on the lottery.
Now he wants to buy a sequence of consecutive hotels, such that the sum of the values of these consecutive hotels is as great as possible - but not greater than M.

You are to calculate this greatest possible total value.
**/

#include <bits/stdc++.h>
#define lli long long
#define MAX 1000005

using namespace std;

lli A[MAX];

int main()
{
    int n, M;
    lli sum = 0;
    cin >> n;
    cin >> M;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int l = 0, r = 0;
    lli ans = 0;

    while (l < n)
    {
        while (r < n && sum + A[r] <= M)
        {
            sum += A[r];
            r++;
        }
        ans = max(ans, sum);
        sum -= A[l];
        l++;
    }

    cout << ans << endl;
    return 0;
}