#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    long long int ans;
    long long int n1 = nums[0] * nums[1] * nums[n - 1];
    long long int n2 = nums[n - 1] * nums[n - 3] * nums[n - 2];
    cout << n1 << " " << n2 << endl;
    if (n1 > n2)
        ans = n1;
    else
        ans = n2;
    return ans;
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
    cout << maximumProduct(nums);
}