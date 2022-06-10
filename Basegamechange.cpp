#include<bits/stdc++.h>
#include<stack>
using namespace std;
typedef long long ll;
// using map unordered_map


vector<bool> primeCheck(int n)
{
    vector<bool> prime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            prime[j] = false;
        }
    }
    return prime;
}
int findmaxDigit(string n,unordered_map<char,int>&l){
       int m=INT_MIN;
    for(int i=0;i<n.size();i++){
        if(m>l[n[i]]){
            m=l[n[i]];
        }
    }
    return m;
}
int findNum(string n, int smallestBase,unordered_map<char,int>&l){
    int m=0;
     for(int i=n.size()-1,j=0;i>=0,j<n.size();i--,j++){
         if(l[n[i]]>smallestBase){
             return -1;
         }
         m+=l[n[i]]*pow(smallestBase,j);
     }
     return m;
}
 int main(){
      unordered_map<char,int>l;
    for(int i=0;i<=9;i++){
            l['0'+i]=i;
    }
    l['A']=10;
    l['B']=11;
    l['C']=12;
    l['D']=13;
    l['E']=14;
    l['F']=15;
    stack<int>primeNum;
primeNum.push(2);
primeNum.push(3);
primeNum.push(5);
primeNum.push(7);
primeNum.push(11);
primeNum.push(13);
primeNum.push(17);
stack<int>compositeNum;
compositeNum.push(4);
compositeNum.push(6);
compositeNum.push(8);
compositeNum.push(9);
compositeNum.push(10);
compositeNum.push(12);
compositeNum.push(14);
compositeNum.push(15);
compositeNum.push(16);
      string n;
      cin>>n;
      vector<bool>prime=primeCheck(100000);
      while(!primeNum.empty()&&!compositeNum.empty()){
          int maxDigit=findmaxDigit(n,l);
          int smallestBase=maxDigit+1;
          int num=findNum(n,smallestBase,l);
          if(num==-1){
              break;
          }
          if(prime[num]){  
              int k=findNum(n,primeNum.top(),l);
              primeNum.pop();
              string j=to_string(k);
              n=j;
              
          }
          else{
              int k=findNum(n,compositeNum.top(),l);
              compositeNum.pop();
              string j=to_string(k);
              n=j;
          }

      }
      cout<<n<<endl;
      return 0;

 }