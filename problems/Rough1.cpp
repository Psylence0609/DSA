#include <bits/stdc++.h>
using namespace std;

bool func(int a, int b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    int i = 0, j = 0;
    while (i < s1.length() && j < s2.length())
    {
        if (s1[i] - '0' > s2[j] - '0')
            return true;
        else if (s1[i] - '0' < s2[j] - '0')
            return false;
        else
        {
            i++;
            j++;
        }
    }
    return false;
}

string largestNumber(const vector<int> &A)
{
    sort(A.begin(), A.end(), func);
    string ans;
    for (int i = 0; i < A.size(); i++)
    {
        ans += to_string(A[i]);
    }
    return ans;
}

int main()
{
    vector<int> A = {29, 91, 20, 56};
    cout << largestNumber(A);
    return 0;
}