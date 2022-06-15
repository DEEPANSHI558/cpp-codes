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
    int height(TreeNode *root, int &h, bool &ans)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = height(root->left, h, ans);
        int r = height(root->right, h, ans);
        if (abs(l - r) > 1)
        {
            ans = false;
        }
        h = max(l, r);
        return h + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        bool ans = true;
        int h = 0;
        int a = height(root, h, ans);
        return ans;
    }
};