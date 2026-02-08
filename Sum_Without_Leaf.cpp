#include<bits/stdc++.h>
using namespace std;
class Tree
{
    public:
    int val;
    Tree* left;
    Tree* right;
    Tree(int val)
    {
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Tree* input_tree()
{
   int val;
    cin>>val;
    if(val==-1)
    {
        return NULL;
    }
    Tree* root = new Tree(val);
    queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
       Tree* f = q.front();
       q.pop();

       int l,r;
       cin>>l>>r;
       Tree *myleft,*myright;
       if(l==-1)
       {
        myleft=NULL;
       }
       else
       {
        myleft = new Tree(l);
       }
       if(r==-1)
       {
        myright=NULL;
       }
       else
       {
        myright = new Tree(r);
       }
       f->left=myleft;
       f->right=myright;

       if(f->left)
       q.push(f->left);
       if(f->right)
       q.push(f->right);
    }
    return root; 
}
int sum_without_leaf(Tree* root)
{
    int sum=0;
    if(root==NULL)
    return 0;
    if(root->left!=NULL || root->right!=NULL)
    {
        sum += root->val;
    }
    sum  += sum_without_leaf(root->left);
   
    sum += sum_without_leaf(root->right);
    
    return sum;
}
int main()
{
    Tree* root = input_tree();
    cout<<sum_without_leaf(root);
    return 0;
}