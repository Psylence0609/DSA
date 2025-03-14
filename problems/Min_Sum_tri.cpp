#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    if (n == 1)
        return A[0][0];
    vector<int> v = {A[0][0]};
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(i + 1);
        curr[0] = A[i][0] + v[0];
        curr[i] = A[i][i] + v[i - 1];
        cout << i << " ";
        for (int j = 1; j < i; j++)
            curr[j] = A[i][j] + min(A[i - 1][j], A[i - 1][j - 1]);
        for (auto r : curr)
            cout << r << " ";
        cout << endl;
        v = curr;
    }
    int res = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        res = min(res, v[i]);
        cout << v[i] << " ";
    }
    return res;
}
int main()
{
    vector<vector<int>> A = {{2}, {6, 6}, {7, 8, 4}};
    cout << endl
         << minimumTotal(A);
    return 0;
}