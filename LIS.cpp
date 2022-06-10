#include<bits/stdc++.h>
#include <vector>
using namespace std;
long long int  LIS(vector<int> &arr){
    vector<long long int >dp(arr.size(),1);
    //checking all the elements below the number Lis Endind at that particular number
    for(int i =1;i<arr.size();i++){   //i 1 se kyunki ussi ka to ek hi Lis hoga
        for(int j=0;j<i;j++){ //harr ek element par end hone waala check karenge last tak ki isme append karke agar bada banta hai ki nahi
            if(arr[j]<arr[i]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }
    }
    //like if we have have to check the longest sybsequence ending at the a particular number for first length is 1 after that there are two options [2,4,1]
    //ending at 4 and is greater than the previous element [4],[2,4] mein se length od [2,4] is 2 therefore it is choosen so max()
    //we have to find the max of the answers
    long long int result=INT_MIN;
    for(int i =0;i<dp.size();i++){
        result=max(dp[i],result);
    }
    return result;

}
int main(){
    int n;
    cin>>n;
    vector<int>d;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        d.push_back(c);
    }
    cout<<LIS(d);
    return 0;
}