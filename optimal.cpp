#include <bits/stdc++.h>
using namespace std;
// optimal page replacement in this find the page that is already present in the queue if it is not then check further that
// map se dhundh sakte hai ki jo abhi vector mein hai wo agge kab ayenge aur unka max index we can store then replace that element with the max index number in the vector remaining
// bahar aa jao jab
int main()
{
    int f, p,pagefault=0;
    cout << "Enter the number of frames";
    cin >> f;
    cout << "enter the number of processes";
    cin >> p;
    unordered_map<int,vector<int>>index;//index keeper
    vector<int> frames;
    vector<int> processes(p, -1);
    for (int i = 0; i < p; i++)
    {
        cin >> processes[i];
        index[processes[i]].push_back(i);
    }
    for(int i=0;i<p;i++){
        for(auto x:frames){
             if(x==processes[i]){
                 continue;
             }
        }
        if(frames.size()<f){
            frames.push_back(processes[i]);
            pagefault++;
        }
        else{
            // check ki aage kitni baar ayya hai how to keep track ki konse konse index par kya ayya hai  
            for(auto x:frames){
                if(find(x))!=index.end()){

                }
                
            }
        }
    }

    return 0;
}