class Solution
{
public:
    //     int helper(string s1,string s2,int n,int m){
    //       int dp[n+1][m+1];
    //         for(int j=0;j<=m;j++){
    //             dp[0][j]=j;
    //         }
    //         for(int i=0;i<=n;i++){
    //             dp[i][0]=i;
    //         }
    //         for(int i=1;i<=n;i++){
    //             for(int j=1;j<=m;j++){
    //                  if(s1[i-1]!=s2[j-1]){
    //                     dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
    //                 }
    //                 else{
    //                     dp[i][j]=dp[i-1][j-1];
    //                 }
    //             }
    //         }
    //         return dp[n][m];
    //     }
    //     space optimization
    int helper(string s1, string s2, int n, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        //             we require only rows then they can be changed
        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            curr[0] = i; // because we are not updating its 0th index
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] != s2[j - 1])
                {
                    curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
                }
                else
                {
                    curr[j] = prev[j - 1];
                }
            }
            prev = curr;
        }
        return prev[m];
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return helper(word1, word2, n, m);
    }
};