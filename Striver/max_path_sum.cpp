/************************************************************

    Following is the Tree node structure

    template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <climits>
long long int helper(TreeNode<int> *root, long long int &m)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }
    long long int leftSum = helper(root->left, m);
    long long int rightSum = helper(root->right, m);
    if (root->left != NULL && root->right != NULL)
    {
        m = max(m, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }
    else if (root->left != NULL)
    {
        return leftSum + root->val;
    }
    else
    {
        return rightSum + root->val;
    }
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.ro

    long long int m = -1;
    helper(root, m);
    return m;
}
// done in leetcode
// the zero is added to remove the negative values in place of negative values we use 0 as we dont include tthem
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
// class Solution {
// public:
//     int helper(TreeNode*root,int &maxSum){
//         if(root==NULL){
//             return 0;
//         }
//         int leftSum=max(0,helper(root->left,maxSum));
//         int rightSum=max(0,helper(root->right,maxSum));
//         maxSum=max(maxSum,leftSum+rightSum+root->val);
//         return max(leftSum,rightSum)+root->val;
//     }
//     int maxPathSum(TreeNode* root) {
//         int maxSum=INT_MIN;
//         helper(root,maxSum);
//         return maxSum;
//     }
// };