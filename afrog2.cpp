#include<bits/stdc++.h>
using namespace std;
int afrog(int arr[],int n,int k){
    int *dp= new int[n];
    for(int k=0;k<n;k++){
        dp[k]=INT_MAX;
    }
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        int s=k;
        int j=i-1;
       while(s>0&&j>=0)
       {
          dp[i]= min(dp[i],abs(arr[j]-arr[i])+dp[j]);
          s--;
          j--;
        }
    }
    return dp[n-1];
}
int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=afrog(arr,n,k);
    cout<<l;
    return 0;
}

