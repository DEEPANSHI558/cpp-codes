int helper(string str1,string str2,int n,int m){
    if(n<0||m<0) return 0;
    if(str1[n]==str2[m]){
        return 1+helper(str1,str2,n-1,m-1);
    }
    else{
        return max(helper(str1,str2,n-1,m),helper(str1,str2,n,m-1));
    } 
}
int LCS(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
//     return helper(str1,str2,n,m);
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m];
    
}
bool compare(string str1, string str2){
    int n=str1.size();
    int m=str2.size();
    if(n!=m+1) return false;
    int i=0;
    int j=0;
    while(i<n){
        if(str1[i]==str2[j]) {
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if(i==n&&j==m) return true;
    return false;
}
bool comp(string&s1,string&s2){
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n=arr.size();
    sort(arr.begin(),arr.end(),comp);  //sorted then according to the length of the strings
    int maxi=1;
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(compare(arr[i],arr[j])&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
        maxi=max(maxi,dp[i]);
        
    }
    return maxi;
}