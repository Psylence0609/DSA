#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

string solve(string A)
{
    if (palindrome(A))
    {
        int carry = 1;
        for (int i = A.length() - 1; i >= 0; i--)
        {
            if (A[i] == '9')
            {
                A[i] = '0';
                carry = 1;
            }
            else
            {
                A[i] = (A[i] - '0') + carry + '0';
                carry = 0;
                break;
            }
        }
        if (carry)
        {
            A = "1" + A;
        }
    }
    string ans;
    int n = A.length();
    if (n % 2) // oddcase
    {
        string s = A.substr(0, n / 2);
        reverse(s.begin(), s.end());
        if (s.compare(A.substr(n / 2 + 1, n / 2)) > 0)
        {
            ans = A.substr(0, n / 2) + A[n / 2] + s;
        }
        else
        {
            string temp = A.substr(0, n / 2 + 1);
            int carry = 1;
            for (int i = temp.length() - 1; i >= 0; i--)
            {
                if (temp[i] == '9')
                {
                    temp[i] = '0';
                    carry = 1;
                }
                else
                {
                    temp[i] = (temp[i] - '0') + carry + '0';
                    carry = 0;
                    break;
                }
            }
            if (carry)
            {
                temp = "1" + temp;
            }
            string s = temp.substr(0, n / 2);
            reverse(s.begin(), s.end());
            ans = temp + s;
        }
    }

    else // even case
    {

        string s = A.substr(0, n / 2);
        reverse(s.begin(), s.end());
        if (s.compare(A.substr(n / 2, n / 2)) > 0)
        {
            ans = A.substr(0, n / 2) + s;
        }
        else
        {
            string temp = A.substr(0, n / 2);
            int carry = 1;
            for (int i = temp.length() - 1; i >= 0; i--)
            {
                if (temp[i] == '9')
                {
                    temp[i] = '0';
                    carry = 1;
                }
                else
                {
                    temp[i] = (temp[i] - '0') + carry + '0';
                    carry = 0;
                    break;
                }
            }
            if (carry)
            {
                temp = "1" + temp;
            }
            string s = temp.substr(0, n / 2);
            reverse(s.begin(), s.end());
            ans = temp + s;
        }
    }

    return ans;
}

int main()
{
    string A;
    cin >> A;
    cout << solve(A);
}