class Solution
{
public:
    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }
    void helper(int index, vector<vector<string>> &output, string s, vector<string> &ans)
    {
        if (index >= s.size())
        {
            output.push_back(ans);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                ans.push_back(s.substr(index, i - index + 1));
                helper(i + 1, output, s, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> output;
        vector<string> ans;
        helper(0, output, s, ans);
        return output;
    }
};