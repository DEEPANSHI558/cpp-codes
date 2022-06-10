#include<iostream>
using namespace std;
int  partition(int si,int ei,int d[]){
    int pivot=d[si]; //we make the first element pivot
    int count=0;
      for(int i =si+1;i<=ei;i++){
          if(d[i]<=pivot){
              count++;
          }
    }
    //swap to get the pivot at its correct position 
    d[si]=d[si+count];
    d[si+count]=pivot;
  
    //now get all the elements smaller than pivot to the left and greater than pivot to the right
    int i=si;
    int j=ei;
    while(i<(si+count)&&j>(si+count)){
        if(d[i]<=pivot){
            i++;
        }
        else if(d[j]>pivot){
            j--;
        }
        else{
            int t=d[i];
            d[i]=d[j];
            d[j]=t;
            i++;
            j--;
        }
    }

    return si+count;
}
void quicksort(int si,int ei,int d[]){
    if(si>=ei){
        return;
    }
    int pi=partition(si,ei,d);
    quicksort(si,pi-1,d);
    quicksort(pi+1,ei,d);

}
int main(){
    int n;
    cout<<"enter the number of elements";
    cin>>n;
    int *d=new int [n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    quicksort(0,n-1,d);
    cout<<"Sorted Array : ";
     for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }


}