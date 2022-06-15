/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;


    public Node() {
        children = new ArrayList<Node>();
    }

    public Node(int _val) {
        val = _val;
        children = new ArrayList<Node>();
    }

    public Node(int _val,ArrayList<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
struct depth
{
    int maxdepth1;
    int maxdepth2;
    depth(int m1, int m2)
    {
        maxdepth1 = m1;
        maxdepth2 = m2;
    }
};
depth helper(Node *root, depth &s)
{
    if (root == NULL)
    {
        depth s(0,0);
        return s;
    }
    for(int i=0;i<root.children.size();i++){
        depth p=helper(root->children[i],s);
        if(p.maxdepth1>s.maxdepth1){
            int temp=s.maxdepth1;
            s.maxdepth1=p.maxdepth1;
            s.maxdepth2=temp;
        }
        else if(p.maxdepth1>s.maxdepth2){
             s.maxdepth2=p.maxdepth1;
        }
    }
    s.maxdepth1++;
    s.maxdepth2;
    return s;
}
int depthfirstsearch(Node *root)
{

    depth d(0, 0);
    int h=0;
    d = helper(root,d);
    return d.maxdepth1 + d.maxdepth2;
}