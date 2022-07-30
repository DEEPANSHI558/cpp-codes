int helper(vector<int> &price, int index, int N)
{
    if (index == 0)
    {
        //         it is used repeatidly
        return N * price[0];
    }
    int nottake = helper(price, index - 1, N);
    int take = INT_MIN;
    if (index + 1 <= N)
    {
        take = price[index] + helper(price, index, N - (index + 1));
    }
    return max(nottake, take);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int N = n;
    vector<vector<int>> dp(n, vector<int>(N + 1, 0));
    for (int i = 0; i <= N; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int nottake = dp[i - 1][j];
            int take = INT_MIN;
            if (i + 1 <= j)
            {
                take = price[i] + dp[i][j - (i + 1)];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][n];
    //     return helper(price,n-1,N);
}
