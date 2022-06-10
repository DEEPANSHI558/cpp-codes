#include<bits/stdc++.h>
using namespace std;
//shortest common subsequence of a two strings is the sum of both the strings -length of the largest common subsequence
//but when we have to print the 
int dp[10000][10000];
string printShortestCommonSubsequence(string s1,string s2,int n,int m){
    //intialization
    for( int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0)
                dp[i][j]=0;;
          
        }
    }
    //filling the wholearray
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //now travesing to print the shortest common subsequence
    int i=n,j=m;
    string s;
    while(i>0&&j>0){
            if(s1[i-1]==s2[j-1]){
                s.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    s.push_back(s1[i-1]);//jahan noi jaale uss wale ko add kar denge bas 
                    i--;
                }else{
                    s.push_back(s2[j-1]);
                    j--;
                }
            }
    }
    //i or j reaches its end
    while(i>0){
        s.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(s2[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
    
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
      int n=s1.length();
     int m=s2.length();
   string k= printShortestCommonSubsequence(s1,s2,n,m);
   cout<<k;
     return 0;
}