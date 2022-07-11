#include <bits/stdc++.h>
void helper(int m, int n, int i, int j, int &ans)
{
    if (i == 0 && j == 0)
    {
        ans++;
        return;
    }
    if (i < 0 || j < 0)
    {
        return;
    }

    //  we can go in two directions
    //  right or up if possible
    helper(m, n, i - 1, j, ans);
    helper(m, n, i, j - 1, ans);

    //            down
}
int uniquePaths(int m, int n)
{
    // Write your code here.

    int ans = 0;
    int i = m - 1;
    int j = n - 1;
    helper(m, n, i, j, ans);
    return ans;
}
/*
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    // Write your code here.
    vector<vector<int>>dp(m,vector<int>(n,0));
//     initialization
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             if(i==0&&j==0) dp[i][j]=1;
             else{
                 int up=0,left=0;
                 if(i>0){ up=dp[i-1][j];}
                 if(j>0){left=dp[i][j-1]; }
                 dp[i][j]=up+left;
             }
     }


}
return dp[m-1][n-1];
}*/