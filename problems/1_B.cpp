#include <bits/stdc++.h>
using namespace std;

// void analize(string s)
// {
//     int pos = 0;
//     for (int i = 1; i < s.length(); i++)
//     {
//         if (s[i] == 'C')
//         {
//             pos = i;
//             break;
//         }
//     }
//     string row_count = s.substr(1, pos - 1);
//     int col_count = stoi(s.substr(pos + 1, s.length()));
//     // cout << row_count << " " << col_count << endl;
//     int i = 1, sum = 26;
//     int temp = col_count;
//     while (true)
//     {
//         if (temp < 0)
//         {
//             i--;
//             break;
//         }
//         i++;
//         temp -= sum;
//         sum = 26 * i;
//     }
//     i--;
//     sum = 26;
//     for (int j = 1; j <= i - 1;)
//     {
//         col_count -= sum;
//         j++;
//         sum = 26 * j;
//     }
//     int div = 26 * i;
//     string ans = "";
//     while (col_count > 0)
//     {
//         int q = col_count / div;
//         ans += (char)(q - 1 + 'A');
//         col_count = col_count % div;
//         div = div / 26;
//     }
//     cout << ans + row_count << endl;
// }

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int l = s.length();
        int x = 1;
        while (x < l && isdigit(s[x]))
        {
            x++;
        }
        if (x > 1 && x < l)
        {

            int col(0);
            for (size_t i = x + 1; i < l; ++i)
            {
                col = col * 10 + (s[i] - '0');
            }

            int pow(26);
            while (col > pow)
            {
                col -= pow;
                pow *= 26;
            }

            col -= 1;
            while (pow != 1)
            {
                pow /= 26;
                printf("%c", col / pow + 'A');
                col %= pow;
            }

            s[x] = 0;
            int pos = 0;
            for (int i = 1; i < s.length(); i++)
            {
                if (s[i] == 'C')
                {
                    pos = i;
                    break;
                }
            }
            string row_count = s.substr(1, pos - 1);
            printf("%s\n", row_count.c_str());
        }
        else
        {
            int col = 0, val = 0, pow = 1;
            int i = 0;
            while (isalpha(s[i]))
            {
                col += pow;
                pow *= 26;
                val = val * 26 + s[i] - 'A';
                i++;
            }
            col += val;
            cout << "R" << s.substr(i, s.length()) << "C" << col << endl;
        }
    }
}