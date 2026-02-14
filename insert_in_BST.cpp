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
    Tree* root = new Tree(val);
    queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
        Tree* p = q.front();
        q.pop();

       int l,r;
       cin>>l>>r;
       Tree* myleft, *myright;
       if(l==-1)
       myleft=NULL;
       else
       myleft= new Tree(l);
        if(r==-1)
       myright=NULL;
       else
       myright= new Tree(r);

       p->left=myleft;
       p->right=myright;

       if(p->left!=NULL)
       q.push(p->left);
       if(p->right)
       q.push(p->left);


    }
    return root;

}
void level_order(Tree* root)
{
    queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
        Tree* f = q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->left!=NULL)
        q.push(f->left);
        if(f->right!=NULL)
        q.push(f->right);
    } 
}
void insert(Tree* root,int val)
{
    if(root==NULL)
    root = new Tree(val);
    if(root->val>val)
    {
        if(root->left==NULL)
        root->left = new Tree(val);
        else
        insert(root->left,val);
    }
    else
    {
        if(root->right==NULL)
        root->right = new Tree(val);
        else
        insert(root->right,val);
    }

}
int main()
{
    Tree* root = input_tree();
    int val;
    cin>>val;
    insert(root,val);
    level_order(root);
    
    return 0;
}