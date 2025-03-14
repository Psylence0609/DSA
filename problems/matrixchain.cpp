#include <iostream>
#include <climits>
using namespace std;

// Function to find the most efficient way to multiply
// a given sequence of matrices
int matrixChainMultiplication(int dims[], int n)
{
    // c[i, j] = Minimum number of scalar multiplications (i.e., cost)
    // needed to compute matrix `M[i] M[i+1] … M[j] = M[i…j]`
    // The cost is zero when multiplying one matrix
    int c[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        c[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) // subsequence lengths
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            c[i][j] = INT_MAX;

            for (int k = i; j < n && k <= j - 1; k++)
            {
                int cost = c[i][k] + c[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < c[i][j])
                {
                    c[i][j] = cost;
                }
            }
        }
    }
    return c[1][n - 1];
}

// Matrix Chain Multiplication Problem
int main()
{
    // Matrix `M[i]` has dimension `dims[i-1] × dims[i]` for `i = 1…n`
    // input is `10 × 30` matrix, `30 × 5` matrix, `5 × 60` matrix
    int dims[] = {10, 30, 5, 60};
    int n = sizeof(dims) / sizeof(dims[0]);

    cout << "The minimum cost is " << matrixChainMultiplication(dims, n);

    return 0;
}
