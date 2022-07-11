class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes herevector<
        // we have to find lis and then trace back

        int index = 0;
        vector<int> dp(n);
        dp[0] = arr[0];
        int maxi = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    dp[i] = max(dp[j] + arr[i], dp[i]);
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};