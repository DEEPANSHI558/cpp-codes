/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> helper(TreeNode<int> *root, int h, vector<int> &ans)
{
    if (root == NULL)
    {
        return ans;
    }
    if (h == ans.size())
    {
        ans.push_back(root->data);
    }
    helper(root->left, h + 1, ans);
    helper(root->right, h + 1, ans);
    return ans;
}
vector<int> getLeftView(TreeNode<int> *root)
{
    int h = 0;
    vector<int> ans;
    return helper(root, h, ans);
}