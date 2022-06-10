#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// find an element that appears one in a sorted array
// Another Simple Solution is to use the properties of XOR (a ^ a = 0 & a ^ 0 = a). The idea is to find the XOR of the complete array. The XOR of the array is the required answer.
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    int *arr=new int[n];
    unordered_map<int, int>p;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        p[arr[i]]++;
    }
    // we have to traverse through the map using iterator
     unordered_map<int, int>:: iterator itr;
    for (itr = p.begin(); itr != p.end(); itr++)
    {
        // itr works as a pointer to pair<string, double>
        // type itr->first stores the key part  and
        // itr->second stores the value part
        if(itr->second==1){
            cout<<itr->first;
        }
     }
    return 0;
}