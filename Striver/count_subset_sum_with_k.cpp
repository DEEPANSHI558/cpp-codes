int helper(vector<int> &num, int target, int n)
{
    if (target == 0)
        return 1;
    if (n == 0)
        return (num[0] == target);

    //     not take
    int nottake = helper(num, target, n - 1);
    int take = 0;
    //     take
    if (num[n] <= target)
    {
        take = helper(num, target - num[n], n - 1);
    }
    return take + nottake;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int ans = 0;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (num[i] <= j)
            {
                take = dp[i - 1][j - num[i]];
            }
            dp[i][j] = nottake + take;
        }
    }
    return dp[n - 1][tar];
    //    return  helper(num,tar,n-1);
}