#include <bits/stdc++.h>
void helper(int n, vector<int> &arr, vector<vector<int>> &output, int index, vector<int> &ans)
{
    //     if(index==n){
    //         output.push_back(ans);
    //         return;
    //     }
    // //     we pick the element to be in the subset

    //     helper(n,arr,output,index+1,ans);
    //     ans.push_back(arr[index]);
    //     helper(n,arr,output,index+1,ans);
    //     the above code is to print all the subsets
    //     now the code for unique subsets
    output.push_back(ans);
    for (int i = index; i < arr.size(); i++)
    {
        if (i == index || (arr[i] != arr[i + 1]))
        {
            ans.push_back(arr[i]);
            helper(n, arr, output, index + 1, ans);
            ans.pop_back();

        } // do not include the index again as it will result in duplicate
        //         else we can put it and call for the next levele
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> output;
    sort(arr.begin(), arr.end());
    vector<int> ans;
    helper(n, arr, output, 0, ans);
    return output;
}