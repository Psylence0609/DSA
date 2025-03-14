#include <bits/stdc++.h>
using namespace std;

void trail(string &num)
{
    while (num[0] - '0' == 0)
        num.erase(0, 1);
}

int main()
{
    string num;
    vector<int> ones;
    vector<int> twos;
    int sum = 0;
    cin >> num;
    trail(num);
    for (int i = 0; i < num.length(); i++)
    {
        sum += num[i];
        if (num[i] - '0' == 1)
            ones.push_back(i);
        if (num[i] - '0' == 2)
            twos.push_back(i);
    }
    int remainder = sum % 3;
    if (!remainder)
    {
        cout << num;
        return 0;
    }
    if (remainder == 2)
    {
        if (!twos.empty())
        { 
            int pos = *(twos.end() - 1);
            num.erase(pos, 1);
            if(num.length()==0)
            cout<<"-1";
            else{
                trail(num);
                if(num.length()==0)
                cout<<"0";
                cout << num;
            }
            return 0;
        }
        else if (ones.size() > 1)
        {
            int pos1 = *(ones.end() - 1);
            int pos2 = *(ones.end() - 2);
            num.erase(pos1, 1);
            num.erase(pos2, 1);
            if(num.length()==0)
            cout<<"-1";
            else{
                trail(num);
                if(num.length()==0)
                cout<<"0";
                cout << num;
            }
            return 0;
        }
        else
            cout << "-1";
    } 
    else if (remainder == 1)
    {
        if (!ones.empty())
        {
            int pos = *(ones.end() - 1);
            num.erase(pos, 1);
            if(num.length()==0)
            cout<<"-1";
            else{
                trail(num);
                if(num.length()==0)
                cout<<"0";
                cout << num;
            }
            return 0;
        }
        else if(twos.size()>1)
        {
            int pos1 = *(twos.end() - 1);
            int pos2 = *(twos.end() - 2);
            num.erase(pos1, 1);
            num.erase(pos2, 1);
            if(num.length()==0)
            cout<<"-1";
            else{
                trail(num);
                if(num.length()==0)
                cout<<"0";
                cout << num;
            }
            return 0;
        }
        else
            cout << "-1";
    }
}