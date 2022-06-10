#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;


int main(){
    int n;
    ll rank;//rank
    cin >> n >> rank;
    string s;
    cin >> s;
    vector<string> str;
    string t = "";
    for(unsigned int i = 0; i < s.size(); i++){
        if(s[i] == ','){
            str.push_back(t);
            t = "";
        }
        else{
            t += s[i];
        }
    }
    str.push_back(t);

    if(r == 1){
        cout << "";
        return 0;
    }
    r--;
    if(r >= 1&& r <= n){
        cout << str[r-1];
        return 0;
    }

    int level = 2;
    r = r - n;
    int m = n;

    while(true){
        //num of ways to get subsets of length "level"
        ll ways = m*(m-1)/2;
        if(r <= ways){
            break;
        }
        else{
            level++;
            m--;
            r = r - ways;
        }
    }

    // cout << level << endl;

    int num = 1;
    int i = 0, j = level-2;
    for(; j < n-1; j++){
        string ans = "";
        for(int x = i; x <= j; x++){
            ans += str[x];
            ans += ',';
        }

        for(int k = j+1; k < n; k++){
            if(num == r){
                ans += str[k];
                cout << ans;
                return 0;
            }
            else{
                num++;
            }
        }
    }

    string ans = "";
    for(unsigned int i = 0; i < str.size(); i++){
        ans += str[i];
        if(i != str.size() - 1){
            ans += ',';
        }
    }
    cout << ans;
    return 0;

}