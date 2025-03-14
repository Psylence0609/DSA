#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> nums)
{
    int count = 0;
    int candidate = 0;
    for (int num : nums)
    {
        if (count == 0)
            candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}
int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int ans = majorityElement(nums);
    cout << ans;
    return 0;
}