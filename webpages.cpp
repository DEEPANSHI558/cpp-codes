#include <iostream>
#include <vector>
#include <string>
using namespace std;

int DFS(vector<vector<int>>& webpages,vector<int>& visited, vector<int>& dp, int start, int end){

    if(start == end) {
        return 0;
    }
    if(dp[start] != -2) {
        return dp[start];
    }
    int answer = -1;
    unsigned int i;
    for(i = 0; i < webpages[start].size(); i++){
        int page = webpages[start][i];
        if(visited[page] != 1){
            visited[page] = 1;
            int t = DFS(webpages,visited, dp, page,end);
            visited[page] = -1;
            if(t != -1){
                if(answer == -1) {
                    answer = t + 1;
                }
                else{
                    answer = min(answer, t + 1);
                }
            }
        }
    }
    dp[start] = answer;
    return answer;

}


int main(){
    string W = "";
    getline(cin, W);
    int n = stoi(W);
    vector<vector<int>> webpages(n);
    for(int i = 0; i < n; i++){
        vector<int> e;
        string t = "";
string s;
        getline(cin, s);
        unsigned int k;
        for( k = 0; k < s.size(); k++){
            if(s[k] == ' '){
                int page = stoi(t) - 1;
                if(page != i)
                { e.push_back(page);
                }
                t = "";
            }
            else{
                t = t + s.substr(k, 1);
            }
        }
        int page = stoi(t) - 1;
        // cout << page << endl;
        if(page != i)
            e.push_back(page);


        // for(int j : e) cout << j << " ";
        // cout << endl;
        webpages[i] = e;
    }

    string f;
    getline(cin, f);
    string ff = "";
    unsigned int i = 0;
    while(f[i] != ' '){
        ff += f[i];
        i++;
    }
    int start = stoi(ff) - 1;

    i++;
    string ee = f.substr(i);
    int end = stoi(ee) - 1;


    vector<int> visited(n, -1);
    vector<int> dp(n, -2);
    visited[start] = 1;
    int ans = DFS(webpages,visited, dp, start, end);
    cout << ans;
}