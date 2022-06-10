#include<bits/stdc++.h>
using namespace std;

int Rodcuttingproblem()
{
  //value array given 
    int dp[n+1][w+1];//n is the length of the array and W is the given length ki hume itne ki hi maximum value nikalni hai 
    //intialzation
    for(int i=0;i<n;i++){
        for(int j=0;j<w+1;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }      
      }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
                //check if the item is less than given W to check if it can be included or not
                if(arr[i-1]<=W){
                    dp[i][j]=max(arr[i-1]+dp[i][j-arr[i-1]],dp[i-1][j]);//if we are including it we can again include it thats as it is unboundes knapsack
                }
                else{
                    dp[i][j]=dp[i-1][j-1];
                }
        }
    }
}