#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<char,int>p;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        p[s[i]]=0;
    }
    string k;
    cin>>k;
    for(int j=0;j<k.size();j++){
        if(k[j]==""){
            continue;
        }
        else{
            int l=tolower(k[j]);
            p[l]++;
        }     
    }
    string h="";
    string t="";
    int i;
    for( i=0;i<s.size();i++){
        if(s[i]==""){
            break;
        }
        if(p[s[i]]>0){
            for(int k=0;k<p[s[i]];k++){
                h+=s[i];
            }
        }
    }
    while(i<s.size()){
        if(p[s[i]]>0){
            for(int k=0;k<p[s[i]];k++){
                t+=s[i];
            }
        }
    }
    string final=h+t;
    cout<<final;
    return 0;


}