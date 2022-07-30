#include<iostream>
using namespace std;
bool find(vector<int>&a){
    int x=a[3];
    int y=a[4];
    int flag=false;
    for(int i=0;i<=2;i++){
        if(a[i]-x==y){
            flag=true;
        }
    }
    return flag;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        vector<int>a;
        for(int i=0;i<5;i++){
            int c;
            cin>>c;
            a.push_back(c);
            bool f=find(a);
            if(f){
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
        }

    }
    return 0;
}