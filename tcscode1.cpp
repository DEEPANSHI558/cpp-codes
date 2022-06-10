#include<iostream>
#include<bits/stdc++.h>
using  namespace std;
int checkforaline(vector<pair<int,int>>s){
    int i=0;
    int j=i+1;
    int count=0;
    bool flag =false;
    while(j<s.size()){
        if(s[i].first==s[j].first||s[i].second==s[j].second){
               if(s[i].second>=s[j].second&&flag==false)
               {   
                   count++;
                   i++;
                   j++;
                   flag=true;
               }
               else if(flag){
                   j++;
               }
               else{
                   count++;
                   i++;
                   j++;
               }
        }
        else if(s[i].second==s[j].second){
            if(s[i].first>=s[j].second){
                j++;
            }
            else{
                count++;
                i++;
                j++;
            }
        }
        else{
               count++;
               i++;
               j++;
        }
    }
    return count+1;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>s;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        s.push_back(make_pair(x,y));
    }
    cout<<checkforaline(s);
}
