#include<iostream>
using namespace std;
void merge(int si,int ei,int d[]){
    int i=si;
    int mid=(si+ei)/2;
    int k=mid+1;
    int size=ei-si+1;
    int *ans=new int[size];
    int l=0;
    while(i<=mid&&k<=ei){
        if(d[i]<d[k]){
            ans[l]=d[i];
            i++;
            l++;
        }
        else{
            ans[l]=d[k];
            k++;
            l++;

        }
    }
    while(i<=mid){
        ans[l]=d[i];
        i++;
        l++;
    }
    while(k<=ei){
        ans[l]=d[k];
        k++;
        l++;
    }
    //copying the elements into the original array
    int m=0;
    for(int i=si;i<=ei;i++){
        d[i]=ans[m];
        m++;
    }
    delete [] ans;

}
void mergesort(int si,int ei,int d[]){
    if(si>=ei){
        return; 
    }
    int mid=(si+ei)/2;
    mergesort(si,mid,d);
    mergesort(mid+1,ei,d);
    merge(si,ei,d);
}
int main(){
    int n;
    cout<<"enter the number of elements";
    cin>>n;
    int *d =new int[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    mergesort(0,n-1,d);
    cout<<"Merge Sort"<<endl;
    cout<<"Sorted Array :";
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }
}