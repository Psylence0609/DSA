// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, q, k;
//     cin >> n >> q;
//     vector<int> a(n), b(q);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         a[i] += a[i - 1];
//     }
//     int arr = 0, x;
//     for (int i = 1; i <= q; i++)
//     {
//         cin >> x;
//         arr += x;
//         k = lower_bound(a.begin(), a.end(), arr) - a.begin();

//         if (k >= n)
//         {
//             cout << n << endl;
//             arr = 0;
//         }
//         else
//         {
//             if (a[k] > arr)
//                 k--;
//             if (k == n - 1)
//             {
//                 cout << n << endl;
//                 arr = 0;
//             }
//             else
//             {
//                 cout << n - k - 1 << endl;
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = int(2e5) + 7;
ll a[maxn], k[maxn], sum[maxn], arrows;

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        scanf(" %lld ", a + i), sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= q; i++)
        scanf(" %lld ", k + i);
    for (int turn = 1, cur; turn <= q; turn++)
    {
        arrows += k[turn];
        if (arrows >= sum[n])
            arrows = 0, printf(" %d\n ", n);
        else
            printf(" %d\n ", n - int(std::upper_bound(sum + 1, sum + 1 + n, arrows) - sum - 1));
    }
    return 0;
}