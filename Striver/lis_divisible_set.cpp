#include <bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] % arr[j]) == 0 && dp[i] < dp[j] + 1)
            {
                hash[i] = j;
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> l;
    l.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        l.push_back(arr[hash[lastIndex]]);
    }
    sort(l.begin(), l.end());
    return l;
}