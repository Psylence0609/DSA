#include <bits/stdc++.h>
using namespace std;

float toFloat(string s)
{
    string num = "";
    int dot = 0, n = s.size();

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        // cout << ch << endl;
        if (ch - '0' >= 0 && ch - '0' <= 9)
        {
            num += ch;
        }
        else if (ch == '.')
        {
            if (dot == 0)
            {
                num += ch;
                dot = 1;
                // cout << i << endl;
            }
            else if (dot == 1)
                break;
        }
    }
    if (num == "")
        return 0;
    const char *c = num.c_str();
    return atof(c);
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    // cout << s << endl;
    cout << toFloat(s);
}