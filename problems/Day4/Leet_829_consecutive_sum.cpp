// Consider the case where you're trying to find a k-digit summation for n.
// Start with sum of the first k digits, kSum1 = 1+2+3+...+k
// If this sum does not work, then the next value of kSum would be calculated by subtracting 1 and adding k+1 (lets call this kSum2).
// kSum2 = kSum1 + k+1 - 1 or kSum2 = kSum1 + k
// Now if this does not work either, let's calculate kSum3
// kSum3 = kSum2 + k+2 - 2 or kSum3 = kSum2 + k

// As you can see, the increment each time is k.
// If there really exists a solution with k digits, then n = kSum1 + m*k or n-kSum1 = m*k.
// So, for any k, it is sufficient to check if n-kSum1 is divisible by k.
// Till when do you check? Till the time kSum1 (called startSum in the code below) becomes greater than n.

#include <bits/stdc++.h>
using namespace std;
int consecutiveNumbersSum(int n)
{
    if (n == 1)
        return 1;
    int i = 1;
    int count = 0;
    int startSum = 1;
    while (startSum <= n)
    {
        int sumToMake = n - startSum;
        if (sumToMake % i == 0)
        {
            count++;
        }
        i++;
        startSum += i;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << consecutiveNumbersSum(n) << endl;
}