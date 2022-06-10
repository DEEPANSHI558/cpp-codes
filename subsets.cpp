#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// to find the all the subsets of the array
int main(){
    int k;
    ll rank;
    cin >> k >> rank;
    string s;
    cin>>s;
    vector<string>p;
    string m="";
    // form an array of strings
    for(unsigned int i=0;i<s.size();i++){
         if(s[i]==','){
             p.push_back(m);
             m="";
         }
         else{
             m+=s[i];
         }
    }
    p.push_back(m);
    if(rank==1){
        cout<<" ";
        return 0;
    } 
    rank--;
    if(rank>= 1&& rank<= k){
        cout << p[rank-1];
        return 0;
    }
    int level = 2;
    rank = rank- k;
    int n = k;
    while(true){
        ll ways = n*(n-1)/2;
        if(rank <= ways){
            break;
        }
        else{
            level++;
            n--;
            rank= rank- ways;
        }
    }
    int number = 1;
    int i = 0, j = level-2;
    for(; j < k-1; j++){
        string a = "";
        for(int x = i; x <= j; x++){
            a += p[x];
            a += ',';
        }

        for(int k = j+1; k < n; k++){
            if(number == rank){
                a += p[k];
                cout << a;
                return 0;
            }
            else{
                number++;
            }
        }
    }

    string a = "";
    for(unsigned int i = 0; i < p.size(); i++){
        a+= p[i];
        if(i != p.size() - 1){
            a += ',';
        }
    }
    cout << a;
    return 0;

    
    // // print the vector to now if it is formed right
    // for(int i=0;i<p.size();i++){
    //     cout<<p[i];
    // }
}