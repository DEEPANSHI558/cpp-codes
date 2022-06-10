/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <queue>
#include <utility>
#include <vector>
#include <map>
using std::vector;

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    // Write your code here.
    //   as the bottom view apprasch
    //     we'll maintain a map<line,node>
    //     we'll maintain a queue of pair<BinaryTreenode<int>*,line>
    //     we'll not update the map once filled we have filled the map with desored node
    queue<pair<TreeNode<int> *, int>> q; // node,line
    map<int, int> map;                   // line,node
    q.push({root, 0});
    while (!q.empty())
    {
        pair<TreeNode<int> *, int> p = q.front();
        q.pop();
        if (map.find(p.second) == map.end())
        { // if the line is not found then we'll update
            map[p.second] = p.first->val;
        }
        if (p.first->left != NULL)
        {
            q.push({p.first->left, p.second - 1});
        }
        if (p.first->right != NULL)
        {
            q.push({p.first->right, p.second + 1});
        }
    }

    for (auto i : map)
    {
        ans.push_back(i.second);
    }
    return ans;
}