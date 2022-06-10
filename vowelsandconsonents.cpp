#include<bits/stdc++.h>
using namespace std;
// int main(){
//     string a;
//     cin>>a;
//     int  v=0;
//     int c=0;
//     for(int i=0;i<a.length();i++){
//         if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
//                       v++;
//         }
//         else if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
//              v ++;
//         }
//         else{
//             c++;
//         }
//     }
//     cout<<"consonanats"<<c<<"   vowels"<<v;
//     return 0;
// }
void removeduplicates(int arr[],int n){
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            for(int j=i+1;j<n-1;j++){
                arr[j]=arr[j+1];
            }
            i=0;
        }
    }
}
int main(){
     int arr[10];
     cout<<"Enter the array";
     for( int i=0;i<10;i++){
         cin>>arr[i];
     }
       for( int k=0;k<10;k++){
         cout<<arr[k];
     }
    //  removeduplicates(arr,10);
    //  for( int k=0;k<10;k++){
    //      cout<<arr[k];
    //  }
  return 0;
}