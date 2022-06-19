void helper(vector<int> &arr, int n, int target, vector<vector<int>> &output, int index, vector<int> &ans)
{
    if (index == n)
    {
        if (target == 0)
        {
            output.push_back(ans);
        }
        return;
    }
    //     this is the case for when the repeatitiion is not allowed if the element is chosen then it cannot be chosem again it means if chosen we cannot choose it again

    ans.push_back(arr[index]);
    helper(arr, n, target - arr[index], output, index + 1, ans);
    ans.pop_back();
    helper(arr, n, target, output, index + 1, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> output;
    vector<int> ans;
    helper(arr, n, k, output, 0, ans);
    return output;
}
// the below implementation is on leetcode when a particular element can be chosen any number of times
// class Solution {
// public:
//     void helper(int n,vector<int>&candidates,int target,int index,vector<vector<int>>&output,vector<int>ans){
//         if(index==n){
//             if(target==0){
//                 output.push_back(ans);
//             }
//             return;
//         }
// //         now we include the number or do not include the number but the target gets reduced
//         if(candidates[index]<=target){
//               ans.push_back(candidates[index]);
//               helper(n,candidates,target-candidates[index],index,output,ans);
//               ans.pop_back();

//         }
//        helper(n,candidates,target,index+1,output,ans);
//             //         not included in the sum

//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         int n=candidates.size();
//         vector<vector<int>>output;
//         vector<int>ans;
//         helper(n,candidates,target,0,output,ans);
//         return output;

//     }
// };