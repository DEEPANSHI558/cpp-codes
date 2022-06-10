#include<bits/stdc++.h>
using namespace std;
//in this we will add only those which have more than one occurance in the sequence only when their indexes are not same in the both the string A=0,1
//A=0,1 then the pair that can be included is A=0 in first and A=1 in second and A=1 in first and A=0 in second
int dp[10000][10000];
int lRepeatingSubsequence(string s1,string s2,int n,int m){
          //initializing
          for(int i=0;i<n+1;i++){
              for(int j=0;j<m+1;j++){
                  if(i==0||j==0){
                      dp[i][j]=0;
                  }
              }
          }
          //now the code variation in the LCS
          for(int i=1;i<n+1;i++){
              for(int j=1;j<m+1;j++){
                  if(s1[i-1]==s2[j-1]&&(i!=j)){ //the only variations
                      dp[i][j]=1+dp[i-1][j-1];
                  }
                  else{
                      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  }
              }
          }
}
int main(){
      string s1;
    cin>>s1;
      int n=s1.length();

   int  k= lRepeatingSubsequence(s1,s1,n,n);
   cout<<k;
     return 0;

}