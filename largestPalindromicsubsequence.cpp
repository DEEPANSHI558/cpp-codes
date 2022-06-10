#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
int lcs(string s1,string s2,int n,int m){
   //intialization
   for(int i=0;i<n+1;i++){
       for(int j=0;j<m+1;j++){
              if(i==0||j==0){
                  dp[i][j]=0;
              }
       }
   }   
   for(int i=1;i<n+1;i++){
       for(int j=1;j<m+1;j++){
           if(s1[i-1]==s2[j-1]){
               dp[i][j]=1+dp[i-1][j-1]; //we call on the remaining array starting from last
           }
           else{
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
   } 
   return dp[n][m];
}
int main(){
    //to find the largest palindromic subsequence we have to find the LCS of the string s and reverse of string s4
    string s;
    cin>>s;
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    int n=s1.length();
    int m=s2.length();
    int ans= lcs(s1,s2,n,m);
    cout<<ans;
    return 0;
}