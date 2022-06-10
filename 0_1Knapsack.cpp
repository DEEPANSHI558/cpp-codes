#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int knapsack(int val[],int wt[],int W,int n){
      vector<vector<int>> dp(n + 1, vector<int>(W + 1));
      for(int i=0;i<=n;i++){
          for(int j=0;j<=W;j++){
              if(i==0||j==0){
                  dp[i][j]=0;
              }
              else if(wt[i-1]<=j){
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
              }
              else{
                  dp[i][j]=dp[i-1][j];
              }

          }
      }
      return dp[n][W];
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int *val=new int[n];
    int *wt=new int[n];
    cout<<"enter the value array"<<endl;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<"enter the weight array"<<endl;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int W;
    cout<<"Enter W"<<endl;
    cin>>W;
    int k=knapsack(val,wt,W,n);
    cout<<"Solution :"<<k;
    return 0;

}