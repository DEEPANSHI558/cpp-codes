/*************************************************************

    Following is the Binary Tree node structure.

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <utility>
// struct player{
//    BinaryTreeNode<int>*node;
//     int line;
//     player(BinaryTreeNode<int>*n ,int l=0):node(n),line(l){};
// };
vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    //     inorder is left root right
    //     pre order is root left right
    //     post order is left right root
    //     a node is bottom view when the node at its horizontal distance from the root
    //     sabke horizontal distance i have to caluculate ki kitne ayenge
    // we have to keep track of height and the horizontal distace jiski height jada
    // we are doing level order traversal and use map for
    map<int, int> map; // line,node; //to keep track of the horizontal distance
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        map[p.second] = p.first->data;
        if (p.first->left != NULL)
        {
            q.push({p.first->left, p.second - 1});
        }
        if (p.first->right != NULL)
        {
            q.push({p.first->right, p.second + 1});
        }
    }
    //     we have to iterate over the map
    vector<int> ans;
    for (auto i : map)
    {
        ans.push_back(i.second);
    }
    return ans;
}
