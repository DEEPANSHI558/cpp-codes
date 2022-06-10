#include<bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
   int  dp[numDenominations+1][value+1];
    memset(dp,0,sizeof dp);
    //initialization
    for(int i=0;i<numDenominations;i++){
            dp[i][0]=1;
    }
    for(int i=1;i<=numDenominations;i++){
        for(int j=0;j<=value;j++){
            if(denominations[i-1]<=j){
                dp[i][j]=dp[i][j-denominations[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[numDenominations][value];
    
}
int main(){
    int n,w;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>w;
    long long int k=countWaysToMakeChange(arr,n,w);
    cout<<k;
}