#include <iostream>
#include<limits.h>
#include<vector>
using namespace std;

int sum(vector<int> freq, int low, int high) { 
        int sum = 0;
        for (int k = low; k <=high; k++){
                sum += freq[k];
        }
        return sum;
}

int minCostBST(vector<int> keys, vector<int> freq, int n) {
        int cost[n][n];
        for (int i = 0; i < n; i++) {
           cost[i][i] = freq[i];
        }
        for (int length=2; length<=n; length++) {
                    for (int i=0; i<=n-length+1; i++) { 
                        int j = i+length-1;
                        cost[i][j] = INT_MAX; 

                    for (int r=i; r<=j; r++) {
                    int c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+sum(freq, i, j);
                    if (c < cost[i][j])
                    cost[i][j] = c;
                    }
                    }
        }
        return cost[0][n-1];
}

int main() {
        vector<int> keys;
        vector<int> freq;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
                int j;
                cin>>j;
                keys.push_back(j);
        }
       for(int i=0;i<n;i++){
                int j;
                cin>>j;
                freq.push_back(j);
        }
        cout << "Cost of Optimal BST is: "<< minCostBST(keys, freq, n);
}
