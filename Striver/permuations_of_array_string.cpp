class Solution
{
public:
    void helper(map<int, bool> &m, vector<vector<int>> &output, vector<int> &ans, vector<int> &nums)
    {
        if (ans.size() == nums.size())
        {
            output.push_back(ans);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!m[nums[i]])
            {
                ans.push_back(nums[i]);
                m[nums[i]] = true;
                helper(m, output, ans, nums);
                m[nums[i]] = false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        map<int, bool> m;
        vector<vector<int>> output;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = false;
        }
        vector<int> ans;
        int n = nums.size();
        helper(m, output, ans, nums);
        return output;
    }
};