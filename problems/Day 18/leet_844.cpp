#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t)
{
    string a = "", b = "";
    for (auto ch : s)
    {
        if (ch == '#')
        {
            if (!a.empty())
                a.pop_back();
        }
        else
            a += ch;
    }
    for (auto ch : t)
    {
        if (ch == '#')
        {
            if (!b.empty())
                b.pop_back();
        }
        else
            b += ch;
    }
    return a == b;
}

int main()
{
    string s = "ab##";
    string t = "c#d#";
    cout << backspaceCompare(s, t);
}