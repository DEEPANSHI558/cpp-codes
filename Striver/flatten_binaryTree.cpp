/************************************************************

    Following is the TreeNode class structure.

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
// we can do it by the concept of morris traversal
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int> *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode<int> *keep = curr->left;
            while (keep->right != NULL)
            {
                keep = keep->right;
            }
            TreeNode<int> *temp = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            keep->right = temp;
        }
        curr = curr->right;
    }
    return root;
}
// we can also do it by using stack
// TreeNode<int> *flattenBinaryTree(TreeNode<int> *root){
//     stacl<TreeNode<int>*>s;
//     s.push(root);
//     while(!s.empty()){
//         TreeNode<int>*curr=s.top();
//         s.pop();
//         if(curr->right){
//             s.push(curr->right);
//         }
//         if(curr->left){
//             s.push(curr->left);
//         }
//         if(!s.empty()){
//             curr->right=s.top();
//         }
//         curr->left=NULL;
//     }
// }
// we can also do it by recursion
TreeNode<int> *flattenTree(TreeNode<int> *root, TreeNode<int> *prev)
{
    if (root == NULL)
    {
        return root;
    }
    flattenTree(root->right, prev);
    flattenTree(root->left, prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *prev = NULL;
    return flattenTree(root, prev);
}
// ths