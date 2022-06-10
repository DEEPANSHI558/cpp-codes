#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTree{
public:
  T data;
  BinaryTree <int>*left;
  BinaryTree <int>*right;
  BinaryTree(T data){
      this->data=data;
      left=NULL;
      right=NULL;
  }

};
BinaryTree <int>*createTree(int arr[],int n ,int i,BinaryTree<int> *root){
     if(i<n){
         BinaryTree <int>*temp=new BinaryTree<int>(arr[i]);
         root=temp;
         root->left=createTree(arr,n,2*i+1,root->left);
         root->right=createTree(arr,n,2*i+2,root->right);
     }
     return root;
}
int findparent(BinaryTree <int>*root,int parent,int nodedata){
    // parent find karne ke liye 
    if(root==NULL){
        return -1;
    }
    if(root->data==nodedata){
        return parent;
    }
    else{
         int a = findparent(root->left,root->data,nodedata);
        if(a>-1){
            return a;
        }
        int b=  findparent(root->right,root->data,nodedata); 
            return b;
    }
}
int getHeight(BinaryTree<int> *root,int level,int val){
    if(root==NULL){
        return 0;
    }
    if(root->data==val){
        return level;
    }
    else{
        int a =getHeight(root->left,level+1,val);
        if(a!=0){
            return a;
        }
        int b=getHeight(root->right,level+1,val);
        return b;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    int h,k;
    cout<<"enter the height";
    cin>>h;
    cout<<"Enter the level order array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BinaryTree <int>*root=new BinaryTree<int>(arr[0]);
    BinaryTree<int> *ans=createTree(arr, n,0,root);
    cout<<"enter the node of which you want the cousins";
    cin>>k;
    int t=findparent(ans,ans->data,k);
    int l=getHeight(ans,0,k);
    // cout<<"t"<<t;
    // cout<<"l"<<l;
    int sum=k;
    for(int i=1;i<n;i++)
    {
        if(getHeight(ans,0,arr[i])==l&&findparent(ans,ans->data,arr[i])!=t)
        {
            sum+=arr[i];
        }
    }
    cout<<sum;
    return 0;  
}