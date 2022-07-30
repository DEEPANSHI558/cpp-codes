int helper(vector<int> &weight, vector<int> &value, int index, int maxWeight)
{
    if (index == 0)
    {
        if (maxWeight >= weight[index])
        {
            return value[index];
        }
        return INT_MIN;
    }
    int nottake = helper(weight, value, index - 1, maxWeight);
    int take = INT_MIN;
    if (maxWeight >= weight[index])
    {
        take = value[index] + helper(weight, value, index - 1, maxWeight - weight[index]);
    }
    return max(take, nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int W = weight[0]; W <= maxWeight; W++)
        dp[0][W] = value[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int nottake = dp[i - 1][j];
            int take = INT_MIN;
            if (weight[i] <= j)
            {
                take = value[i] + dp[i - 1][j - weight[i]];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][maxWeight];
    //     return helper(weight,value,n-1,maxWeight);
}