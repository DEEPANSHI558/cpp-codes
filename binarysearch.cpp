#include<iostream>
using namespace std;
int binarysearch(int arr[],int s,int e,int x){
    if(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==x){
            return mid;
        } 
        else if(arr[mid]<x){
           return binarysearch(arr,mid+1,e,x);
        }
        else if(arr[mid]>x){
            return binarysearch(arr,s,mid-1,x);
        }
    }
    return -1;
}
int main(){
    cout<<"Binary search"<<endl;
    int n,x;
    cout<<"enter the size of the array:";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter the sorted array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the element to be searched :";
    cin>>x;
    int index=binarysearch(arr,0,n-1,x);
    if(index!=-1){
        cout<<"The element "<<arr[index]<<" "<<"is found at index  "<<index;
    }else{
        cout<<"Element not found";
    }
    return 0;
}