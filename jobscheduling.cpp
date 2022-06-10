#include<bits/stdc++.h>
#include<climits>
#include<vector>
using namespace std;
struct job{
    int profit;
    int deadline;
};
int profit(vector<job> jobs,int n){
    // sort on the basis of profits in descending prder
    sort(jobs.begin(),jobs.end(),[](job&a ,job&b){
        return a.profit>b.profit;
    });
    int profit=0;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        if(arr[jobs[i].deadline]!=0){
           continue;
        }
        else{
            profit+=jobs[i].profit;
            arr[jobs[i].deadline]=jobs[i].profit;
        }
    }
     return profit;
}
int main(){
    vector<job> jobs={
        {100,2},{10,1},{15,2},{27,1}
    };
   cout<<"minimin penalties "<< profit(jobs,jobs.size());
   return 0;

}