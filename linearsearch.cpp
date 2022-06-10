#include<bits/stdc++.h>
using namespace std;
int linearSearch(int arr[],int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;

}
int  main(){
    cout<<"linear search"<<endl;
    int n,x;
    cout<<"enter the size of the array:";
    cin>>n;
    int *arr=new int[n];
    cout<<"enter the array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter the element to be searched :";
    cin>>x;
    int index=linearSearch(arr,n,x);
    if(index!=-1){
        cout<<"The element "<<arr[index]<<" "<<"is found at index  "<<index;
    }else{
        cout<<"Element not found";
    }


        return 0;
}