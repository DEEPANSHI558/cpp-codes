#include<bits/stdc++.h>
using namespace std;
int removeduplicates(char arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n;){
        if(arr[i]==arr[i+1]){
            for(int j=i+1;j<n-1;j++){
                arr[j]=arr[j+1];
            }  
            n--;
        }
        else{i++;}
    }
    return n;
}
int main(){
    int n;
    cin>>n;
    char *a =new char [n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=removeduplicates(a,n);
    for(int i=0;i<=k;i++){
        cout<<a[i];
    }
    return 0;
}