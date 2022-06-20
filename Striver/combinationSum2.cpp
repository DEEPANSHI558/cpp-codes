class Solution {
public:
    void helper(int n, int target,vector<int>&candidates,vector<int>&ans,vector<vector<int>>&output,int index){
        
            if(target==0){
                output.push_back(ans);
            }
        
        for(int i=index;i<n;i++){
            if(i!=index&&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ans.push_back(candidates[i]);
            helper(n,target-candidates[i],candidates,ans,output,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>output;
        sort(candidates.begin(),candidates.end());
        vector<int>ans;
        helper(candidates.size(),target,candidates,ans,output,0);
        return output;
    }
};