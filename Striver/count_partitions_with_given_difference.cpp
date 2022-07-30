int mod = (int)(1e9 + 7);
int helper(int n, int target, vector<int> &arr)
{
    //     base case when index is 0
    if (n == 0)
    {
        if (arr[0] == 0 && target == 0)
            return 2; // when the target is zero but the arr[index]==0 we can have two ways by either taking the zero or not taking the zero to two ways
        if (target == 0 || arr[0] == target)
            return 1; // if the target is not equal to zero and index 0 is equal to target we have one case only to take it
        return 0;     // means target cannot be reached ab
    }

    //        nottake in the subset
    int nottake = helper(n - 1, target, arr);
    int take = 0;
    if (arr[n] <= target)
    {
        take = helper(n - 1, target - arr[n], arr);
    }
    return (take + nottake) % mod;
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    //     set1+set2=sum;
    //     set1-set2=diff;
    //     2set1=sum+difference;
    //     set1=sum+difference/2;
    //     set2=sum-difference/2;
    //     set1>set2
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    //     if(sum-d<0)return 0; //has to be greater than zero
    //     if((sum-d)%2=0) return 0; //has to be an integer
    if (sum - d < 0 || (sum - d) % 2)
        return false;
    //     tabulation
    int target = (sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (take + nottake) % mod;
        }
    }
    return dp[n - 1][target];

    //     return helper(n-1,(sum-d)/2,arr);
}
