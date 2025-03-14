#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int maxi = nums[0];
    int mini = nums[0];
    int ans = maxi;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < 0)
            swap(maxi, mini);

        maxi = max(nums[i], maxi * nums[i]);
        mini = min(nums[i], mini * nums[i]);
        ans = max(ans, maxi);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << maxProduct(a) << endl;
}