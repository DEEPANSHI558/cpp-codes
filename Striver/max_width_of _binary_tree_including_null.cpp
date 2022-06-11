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
    int widthOfBinaryTree(TreeNode *root)
    {
        int max_width = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int miN = q.front().second;
            int first, last;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                long long curr_id = q.front().second - miN;
                TreeNode *node = q.front().first;
                q.pop();
                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;
                if (node->left)
                {
                    q.push({node->left, 2 * (curr_id) + 1});
                }
                if (node->right)
                {
                    q.push({node->right, 2 * (curr_id) + 2});
                }
            }
            max_width = max(max_width, last - first + 1);
        }
        return max_width;
    }
};