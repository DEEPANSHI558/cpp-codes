#include<bits/stdc++.h>
using namespace std;
int afrog(int arr[],int n){
    int *dp= new int[n];
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2;i<n;i++){
        dp[i]= min(abs(arr[i-1]-arr[i])+dp[i-1],abs(arr[i-2]-arr[i])+dp[i-2]);
    }
    return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k=afrog(arr,n);
    cout<<k;
    return 0;
}

