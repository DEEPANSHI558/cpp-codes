#include<bits/stdc++.h>
#include <boost/functional/hash.hpp>
#include <unordered_map>
#include <utility>
using namespace std;
typedef pair<int,int> pair;
 
int main(){
    int n,m;
    cin>>n>>m;
    int t=n;
    vector<vector<int> > v( n , vector<int> (n, 0)); 
    // create a map for all visited block
    unordered_map<pair, int, boost::hash<pair>>o;
    // writing the points in the matrix
    string start;
    int p=0;
    string s1="",s2="";
    while(p<start.size()){
            if(start[p]==','){
                s2+=start[p];
            }
            else{
                s1+=start[p];
            }
            p++;
    }
    int x=stoi(s1),y=stoi(s2);
    o.insert({make_pair(x,y),true});
    while(t--){
        string s;
        cin>>s;
        int k,l=0;
        cin>>k;
        string i="",j="";
        while(l<s.size()){
            if(s[l]==','){
                j+=s[l];
            }
            else{
                i+=s[l];
            }
            l++;
        }
        v[stoi(i)][stoi(j)]=k;
        o.insert({make_pair(stoi(i),stoi(j)),false});
    }
    // vector for directions
    vector<char>directions;
    int sum=0;
    int resx=x,resy=y;
    do{
           char c;
           cin>>c;
           if(c=='R'){
               if(resx>0&&resx<n&&resy+1>0&&resy+1<n){
                     sum+=v[resx][resy+1]-1;
                 if(o.find(make_pair(resx,resy+1))!=o.end()){
                     o[make_pair(resx,resy+1)]=true;
                 }  
                 resy+=1;
               }
                cout<<"*** Mission Failed! ***";
                   return 0;
                 
           }
           else if(c=='L'){
               if(resx>0&&resx<n&&resy-1>0&&resy-1<n){
                          sum+=v[resx][resy-1]-1;
                  if(o.find(make_pair(resx,resy-1))!=o.end()){
                     o[make_pair(resx,resy-1)]=true;
                 }  
                 resy-=1;
               }
               else{
                   cout<<"*** Mission Failed! ***";
                   return 0;
               }
           }
            else if(c=='U'){
               if(resx-1>0&&resx-1<n&&resy>0&&resy<n){
                          sum+=v[resx-1][resy]-2;
                  if(o.find(make_pair(resx-1,resy))!=o.end()){
                     o[make_pair(resx-1,resy)]=true;
                 }  
                 resx-=1;
               }
               else{
                   cout<<"*** Mission Failed! ***";
                   return 0;
               }
           }
            else if(c=='D'){
               if(resx+1>0&&resx+1<n&&resy>0&&resy<n){
                          sum+=v[resx-1][resy]-2;
                  if(o.find(make_pair(resx-1,resy))!=o.end()){
                     o[make_pair(resx-1,resy)]=true;
                 }  
                 resx+=1;
               }
               else{
                   cout<<"*** Mission Failed! ***";
                   return 0;
               }
           }
           directions.push_back(c);
    }while(directions[directions.size()-1]!='Q');
   unordered_map<pair<int,int>,bool>:: iterator it=o.begin();
   while(it!=o.end()){
       if(it->second==false){
           cout<<"*** Mission Failed! ***";
           return 0;
       }
   }
   cout<<"*** Mission Passed! ***"<<"\n"<<"You have collected maximum points :"<<sum;
    return 0;
   

}