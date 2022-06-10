#include<bits/stdc++.h>
using namespace std;
int minElementIndex=-1;
int maxElementIndex=-1;
// vector<int,int> findmin(vector<int>p,int n){
//     int k=INT_MAX;
//     int h=-1;
//     for(int i=0;i<n;i++){
//         if(k>p[i]){
//             k=p[i];
//             h=i;
//         }
//     }
//     vector<int,int> ans;
//     ans.push_back(k);
//     ans.push_back(h);
//     return ans;
// 
// vector<int,int> findmax(vector<int>p,int n){

// }
void swap(vector<int>p,int k,int l){
    int temp=p[k];
    p[k]=p[l];
    p[l]=temp;

}
int minparcels(vector<int> p,int n,int k){
    // vector<int,int>m=findmin(p,n);
    // int k=p.first;
    // int h=p.second;
  
     for(int i=0;i<n;i++){
            if(i==0){
                     maxElementIndex = *max_element(p.begin(),p.end()) - p.begin();
                     minElementIndex = *min_element(p.begin(),p.end()) - p.begin();
                     if(p[k]*p[maxElementIndex]>p[minElementIndex]*(p[k]+p[maxElementIndex])){
                             swap(p,k,maxElementIndex);
                             sum+=p[k]*p[maxElementIndex];
                     }
                    else{
                             swap(p,minElementIndex,k);
                             swap(p,k,maxElementIndex);
                    }
            }
            else{
                
            }
            
   

}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>parcels;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        parcels.push_back(s);
    }
    cout<<minparcels(parcels,n,k);
    return 0;
}