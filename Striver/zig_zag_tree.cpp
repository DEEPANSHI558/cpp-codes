/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    //     we have to keep track of the height if height is even left to right using queue
    //     and if height is odd then we have to keep a stack and then put it in the
    void helper(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> a;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                a.push_back(front->val);
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            ans.push_back(a);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        int h = 0;
        helper(root, ans);
        for (int i = 0; i < ans.size(); i++)
        {
            if (i % 2 != 0)
            {
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
};