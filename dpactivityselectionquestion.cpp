#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct Job{
    int start;
    int finish;
};
int find(vector<Job> jobs){
    // we have to sort a vector based on its start time
    sort(jobs.begin(),jobs.end(),[](Job&a ,Job&b){
        return a.start<b.start;
    });
    // ek vector banana hai jiska size sixe of jobs ke equal ho aur usse initialize karna hai 1 se sabko vector<int> vect(size, 10);
     vector<int> ans(jobs.size());

    for(int i=0;i<jobs.size();i++){
        for(int j=0;j<i;j++){
            if(jobs[i].start>jobs[j].finish && ans[i]<ans[j]){
                ans[i]=ans[j];
            }
        }
        ans[i]++;
    }
    // we have to return the max element in the 
    return *max_element(ans.begin(),ans.end());
    
}
int main(){
    vector<Job> jobs= {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };
    cout<<"the maximum number of non conflicting jobs "<<find(jobs);
    return 0;

}