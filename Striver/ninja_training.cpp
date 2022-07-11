int helper(vector<vector<int>> &points, int index, int last, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        int maxi = 0;
        for (int j = 0; j < 3; j++)
        {
            if (j != last)
            {
                maxi = max(maxi, points[index][j]);
            }
        }
        return maxi;
    }
    if (dp[index][last] != -1)
        return dp[index][last];
    int maxi = 0;
    for (int j = 0; j < 3; j++)
    {
        if (j != last)
        {
            int ans = points[index][j] + helper(points, index - 1, j, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[index][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(points, n - 1, 3, dp);
}