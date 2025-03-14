#include <bits/stdc++.h>
using namespace std;
int main()
{
    string A, B;
    cin >> A >> B;
    int n = A.length(), m = B.length();
    string ans(n + m, '0');
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int temp = (A[i] - '0') * (B[j] - '0') + ans[i + j + 1] - '0';
            cout << temp << endl;
            ans[i + j + 1] = temp % 10 + '0'; // set the remainder as i+j+1 digit
            ans[i + j] += temp / 10;          // add the carry to the next digit
            cout << ans << endl;
        }
    }
    for (int i = 0; i < ans.length(); i++)
        if (ans[i] != '0')
            cout << ans.substr(i);
}