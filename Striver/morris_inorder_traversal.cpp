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
    vector<int> inorderTraversal(TreeNode *root)
    {
        //         morris method for inorder traversal in BST
        //         this uses threaded binary tree in threaded binary tree we create link to
        //         in this the right most of the left subtree points to the current now we have tp code it
        //         three cases we have in this
        //         case1 :if it doesn't have a left subtree it means it is in the inorder traversal
        //         case2:if it has a left subtree we cannot come back kagain here so we hae to create a thread from the rightmost of the leftsubtree to the current
        //         case3:now again if we go to the right and reach the current hjow do we know where to move so we find the rightmost pf the left subtree and check whether a thread exists or not if it exists then we have to remove it and move to the curr=curr->right;
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
                    pre->right = curr; // this is the thread we created
                    curr = curr->left;
                }
                else
                {
                    pre->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};