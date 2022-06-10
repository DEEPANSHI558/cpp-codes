#include<bits/stdc++.h>
using namespace std;
int getAllWays(int a, int b) {
	// Write your code here
    int k=floor(sqrt(a));
    int dp[k+1][a+1];
    memset(dp,0,sizeof dp);
    //initialization
    int *arr=new int [k+1];
    for(int i=0;i<=k;i++){
        arr[i]=i;
    }
    for(int i=0;i<=k;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=a;j++){

            int l=pow(arr[i-1],b);
            if(arr[i-1]<=sqrt(j)){
                dp[i][j]=dp[i-1][j-l]+dp[i-1][j];
            }  else{
            dp[i][j]=dp[i-1][j];
       	 }
        }
    }
    return dp[k][a];
    
}
int main(){
    int a ,b;
    cin>>a;
    cin>>b;
    int k=getAllWays(a,b);
    cout<<k;

}