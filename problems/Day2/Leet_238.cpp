#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> forw(n, 0);
    vector<int> back(n, 0);
    forw[0] = 1;
    back[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        forw[i] = forw[i - 1] * nums[i - 1];
        back[n - i - 1] = back[n - i] * nums[n - i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << forw[i] << " " << back[i] << endl;
    // }
    for (int i = 0; i < n; i++)
    {
        nums[i] = forw[i] * back[i];
    }
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans = productExceptSelf(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}