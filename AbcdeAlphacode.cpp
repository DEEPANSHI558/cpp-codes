#include<iostream>
#include<vector>
using namespace std;

//  long long int f(string &s ,int n){
//     if(n==1||n==0){//for corner cases like because  if 2 5 1 1 1  "5" will not be able to consider anything beyound 2 therefore 
//         return 1;
//     }
//     if(dp[n]!=-1){ // if the value is present then we return the value
//         return dp[n];
//     }
//     long long int ans=0;
//     if((s[n-1]-'0')>0){
//           ans+=f(s,n-1);
//     }
//     if(n-2>0&&(s[n-2]-'0')>0&&((s[n-2]-'0')*10+(s[n-1]-'0'))<=26){
//         ans+=f(s,n-2);

//     }
//     return dp[n]=ans;
// }
long long int gg(string &s){
    //initialization 
    vector<long long int> dp(s.size(),0);
    dp[0]=dp[1]=1;
    if(((s[0]-'0')*10+(s[1]-'0'))<=26){
        dp[1]+=1;
    }
    for(int i=2;i<s.size();i++){
        dp[i]=dp[i-1]+(((((s[i-1]-'0')*10)+(s[i]-'0'))<=26)?dp[i-2]:0);
    }
    return dp[s.size()-1];
}
int main(){

   string s;
   cin>>s;
   while(s[0]!='0')
   {
        
        cout<<gg(s);
        cin>>s;

   }
}
  

