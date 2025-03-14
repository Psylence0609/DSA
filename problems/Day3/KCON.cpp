// You are given an array A with size N (indexed from 0) and an integer K. Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.
// For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.
// You have to find the maximum subarray sum of the array B. Fomally, you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

// Input:
// 2
// 2 3
// 1 2
// 3 2
// 1 -2 1

// Output:
// 9
// 2

#include <bits/stdc++.h>
using namespace std;

int Kadane(vector<int> nums)
{
    int max_so_far = INT32_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        max_ending_here = max_ending_here + nums[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int sum(vector<int> nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum = sum + nums[i];
    return sum;
}

vector<int> concat(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        nums.push_back(nums[i]);
    return nums;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, ans;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        if (k == 1)
            ans = Kadane(nums);
        else if (sum(nums) < 0)
            ans = Kadane(concat(nums));
        else
            ans = Kadane(concat(nums)) + (k - 2) * sum(nums);
        cout << ans << endl;
    }
}