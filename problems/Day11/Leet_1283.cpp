#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> nums, int n, int h)
{
    for (auto it : nums)
    {
        h -= (it + n - 1) / n;
    }
    // cout << "mid,h=" << n << h << endl;
    return h >= 0;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int l = 1, ans;
    int r = *max_element(nums.begin(), nums.end()) + 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // printf("l=%d,r=%d,mid=%d\n", l, r, mid);
        // printf("check(%d,%d)\n", mid, threshold);
        if (check(nums, mid, threshold))
        {

            r = mid - 1;
            ans = mid;
            // cout << ans << endl;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {19};
    int threshold = 5;
    // cout << check(nums, 4, 5) << endl;

    cout << smallestDivisor(nums, threshold);
    return 0;
}