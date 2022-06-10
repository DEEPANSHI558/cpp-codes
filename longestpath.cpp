#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
vector<int> graph[1000005];
//ye har ek node jo bada wo hai 
int f(int x){
     if(dp[x]!=-1){
         return dp[x];

     }
     int maxVal=0;
     bool leaf=true;
     //har ek neighbour se maximum path nikaal lenge aur idhar daal denge
     for(int neighbours:graph[x]){
           leaf=false;//ek bhi baar chala matlab hai neighbours
           maxVal=max(maxVal,f(neighbours));
     }
     
     return dp[x]=((leaf)? 0 :1+maxVal);
}

int main(){
    //taking the input;
    memset(dp,-1,sizeof dp);
    int n,m;
    cin>>n>>m;
    //m is th number of edges
    for(int i=0;i<m;i++){
          int x,y;
          cin>>x>>y;
          graph[x].push_back(y);
    }
    //ab saare vertives mein se jo bhi max hai wo ans hai
    int result=0;
    //n is the number of edges
    //saare nodes se maximum path nikala fir unmese sabse bada
    for(int i=1;i<=n;i++){
        result=max(result,f(i));
    }
    cout<<result<<"\n";

    return 0;
}