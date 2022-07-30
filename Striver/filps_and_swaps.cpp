#include <bits/stdc++.h>
using namespace std;
void swap(string &s, int &coins, int a)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j && coins >= a)
    {
        if (s[i] == '1' && s[j] == '0')
        {
            s[i] = '0';
            s[j] = '1';
            coins = coins - a;
        }
        else if (s[i] == '0')
        {
            i++;
        }
        else if (s[j] == '1')
        {
            j--;
        }
    }
}
void flip(string &s, int &coins, int b)
{
    // first first we have to find and the change it
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1' && coins >= b)
        {
            s[i] = '0';
            coins = coins - b;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int coins, a, b;
    cin >> coins >> a >> b;
    if (a < b)
    {
        swap(s, coins, a);
        flip(s, coins, b);
    }
    else
    {
        flip(s, coins, b);
        swap(s, coins, a);
    }

    cout << stoull(s, 0, 2);

    return 0;
}