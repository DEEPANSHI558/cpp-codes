int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    int maxi = 0;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                count[i] = count[j];
            }
            else if (arr[j] < arr[i] && dp[j] + 1 == dp[i])
            {
                count[i] += count[j];
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            ans += count[i];
    }
    return ans;
}