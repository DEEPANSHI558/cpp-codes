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
    vector<int> preorderTraversal(TreeNode *root)
    {
        //         morris preorder traversal
        //         in this we again have to use the threaded binary tree
        //         case 1:when the current doesn't have a left then it is the root it is printed
        //         case 2:when the current have a left we find the rightmost of the left subtree and then link it to the current and print the current which means it is the root
        //         case 3:if we it has a left and we move find the rightmost of the left subtree we remove the link and go to current-right and comtinue ;
        TreeNode *curr = root;
        TreeNode *pre;
        vector<int> ans;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                pre = curr->left;
                while (pre->right && pre->right != curr)
                {
                    pre = pre->right;
                }
                if (pre->right == NULL)
                {
                    pre->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};