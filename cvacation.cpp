#include<bits/stdc++.h>
using namespace std;
int vacation(int **arr,int n){
    int *dp=new int[n];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    int ma=INT_MIN;
    int keep=-1;
    for(int i=0;i<n;i++){
        ma=INT_MIN;
        int p=-1;
        for(int j=0;j<3;j++){
            // finding the maximum element and keeping its index safe so next time we do not do the same activity;
             if(j!=keep){
                if(ma<arr[i][j]){
                   p=j;  
                   ma=arr[i][j]; 
                }    
               }
        }
        keep=p;
        // cout<<keep;
        dp[i]=max(dp[i],dp[i-1]+ma);
    }
    return dp[n-1];

}
int main(){
      int n;
      cin>>n;
      int **arr=new int*[n];
      for(int i=0;i<n;i++){
         arr[i]=new int[3];
          for(int j=0;j<3;j++){
              cin>>arr[i][j];
          }
      }
      int s=vacation(arr,n);
      cout<<s;
      return 0;
}