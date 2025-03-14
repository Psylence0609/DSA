#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2 != 0)
            printf("1 %d %d\n", n / 2, n / 2);
        else if (n % 4 == 0)
            printf("%d %d %d\n", n / 2, n / 4, n / 4);
        else
            printf("%d %d %d\n", n / 2 - 1, n / 2 - 1, 2);
    }
}