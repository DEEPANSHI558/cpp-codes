#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// vector<ll> dp(1000005,0);
ll f(int n,int k ,int l, vector<ll> &dp){
    //base case that if this is the current state then it is a winning state 
    if((n==1)||(n==l)||(n==k)){
        return dp[n]=1;
    }
    //if the value previously exists 
    if(dp[n]!=-1){
        return dp[n];
    }
    //if it doesnt then calculate
    return dp[n]=1-((((n-1)>=0)?f(n-1,k,l,dp):1)&&(((n-k)>=0)?f(n-k,k,l,dp):1)&&(((n-l)>=0)?f(n-l,k,l,dp):1));

}

int main(){
    int l,k,m;
    cin>>l>>k>>m;
    vector<ll> dp(100005,-1);
    f(10000,k,l,dp);
    // int l,k,m;
    // cin>>l>>k>>m;
    // // dp[1]=1;
    // // dp[k]=1;
    // // dp[m]=1;
    // // //these are the winning states
    // // for (int i=2;i<1000005;i++){
    // //     dp[i]=dp[i-1]&&(((i-k)>=0)?dp[i-k]:1)&&(((i-l)>=0)?dp[i-l]:1);
    // //     dp[i]=1-dp[i];
    // // }
    // //taking the queries same for both 
    while(m--){
        long long int  c;
        cin>>c;
        if(dp[c]){
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
}
