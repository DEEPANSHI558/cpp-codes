#include<bits/stdc++.h>
using namespace std;
int dp[10000][10000];
void lcs(string s1,string s2,int n,int m){
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
   cout<<dp[n][m];
}
string printlcs(string s1,string s2){
     string s="";
    int n=s1.length();
    int m=s2.length();
    lcs(s1,s2,n,m);
    while(n>=0&&m>=0){
        if(s1[n]==s2[m]){
               s=s+s1[n];
               n--;
               m--;
        }
        else{
            if(dp[n][m-1]>dp[n-1][m]){
                m--;
            }else{
                n--;
            }
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    //  int n=s1.length();
    //  int m=s2.length();
   string k= printlcs(s1,s2);
   cout<<k;
     return 0;
}