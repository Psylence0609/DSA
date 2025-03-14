#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    string ans = "";

    int n = s.size();
    stack<string> st;
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        // cout << ch << endl;
        if (s[i] == ' ' && temp != "")
        {
            // cout << 1 << endl;
            st.push(temp);
            temp = "";
        }
        else if (ch == ' ' && temp == "")
            continue;
        else if (ch == ',')
        {
            st.push(temp);
            st.push(",");
            temp = "";
        }

        else if ((ch - 'a' >= 0 && ch - 'z' < 26) || (ch - 'A' >= 0 && ch - 'Z' < 26))
        {
            temp += ch;
            // cout << "Added to temp " << temp << endl;
        }
        else
        {
            ans += temp + " ";
            while (st.size() != 1)
            {
                string t = st.top();
                if (t == ",")
                    ans += t;
                else
                    ans += t + " ";
                st.pop();
            }
            ans += st.top() + ch + " ";
            st.pop();
            temp = "";
        }
    }
    cout << ans;
}