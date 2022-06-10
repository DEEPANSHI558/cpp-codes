#include<bits/stdc++.h>
using namespace std;
// it is the same as mcm 
// in this question we have to return the minimum number of partition that can be done to name all the partitiions palindrome we will see it through the approach of matirx chain multiplication
// recursive +memoization //top down approach
int dp[10000][10000];
bool ispalindrome(string a,int i,int j ){
    while(i<=j){
        if(a[i]==a[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int palidromePartitioning(string a ,int i, int j){
    // base case we will see the smallest invalid approach k is less than as we cannot make two partitiions from it as if k =j then the partitiions will be i ,k but k+1 that is j+1 that dpes not exist
    // memoization of this approach
    // optimization to this code can be ew checked if the bigger problem is solved first or not but we didint check the i to k part and k+1 to j part 
    if(i>=j){
        return 0;
    }
    if(ispalindrome(a,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=((dp[i][k]!=-1)?dp[i][k]:palidromePartitioning(a,i,k))+((dp[k+1][j]!=-1)?dp[k+1][j]:palidromePartitioning(a,k+1,j))+1;
        // more optimized code
        // first we did temp=solvee(a,i,k)+solvee(a,k+1,j)+1
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;

}
int main(){
    string a;
    cin>>a;
    int n=a.length();
    memset(dp,-1,sizeof dp);
    int k= palidromePartitioning(a,0,n-1);
    cout<<k;
}