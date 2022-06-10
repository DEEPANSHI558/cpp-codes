#include<bits/stdc++.h>
using namespace std;
bool checkpalindrome(string str,int i,int e)
{
    while (i<e)
    {
        if (str[i++] != str[e--])
        {
           return false;
        }
    }
    return true;
}
int checkpalindromecount(string str,int c){
    int count=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==str[i+c]&&i+c<str.length()){
            if(checkpalindrome(str,i,i+c)){
                  count++;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int t;
    cin>>t;
    int count=0;
    int *c=new int[t];
    int j=0;
    while(t>0){
        int l;
        cin>>l;
        c[j]=l;
        j++;
        t--;
    }
    for(int i=0;i<j;i++){
        count=count+checkpalindromecount(str,c[i]);
    }
    cout<<count;
    return 0;
}