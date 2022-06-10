#include<iostream>
#include<bits/stdc++.h>
int dp[10000][10000];
using namespace std;
int LCS_recursive(string s1,string s2,int i,int j){
         if(s1[i]=='\0'||s2[j]=='\0')
         {
             return 0;
         }
        if(s1[i]==s2[j]){
            return 1 + LCS_recursive(s1,s2,i+1,j+1);
        }
        else{
            return max(LCS_recursive(s1,s2,i+1,j),LCS_recursive(s1,s2,i,j+1));
        }

}
int LCS(string s1,string s2,int i,int j,int n,int m){
       for(int i=0;i<=n;i++){
           for(int j=0;j<=m;j++){
               if(i==0||j==0){
                   dp[i][j]=0;
               }
               else if(s1[i-1]==s2[j-1]){
                   dp[i][j]= dp[i-1][j-1]+1;
               }
               else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       return dp[n][m];
}
int main(){
    string s1;
    string s2;
    cout<<"Enter two strings :";
    cin>>s1;
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    int ans=LCS_recursive(s1,s2,0,0);
    int a=LCS(s1,s2,0,0,n,m);
    cout<<"Length of longest common subsequence is (using recursion) :"<<ans<<endl;
    cout<<"Length of longest common subsequence is (using dp)"<<a;
    return 0;

}