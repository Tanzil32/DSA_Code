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
bool search(Tree* root,int val)
{
    if(root==NULL)
    return false;
    if(root->val==val)
    return true;
    if(val<root->val)
    return search(root->left,val);
    return search(root->right,val);

}
int main()
{
    Tree* root = input_tree();
    int val;
    cin>>val;
    if(search(root,val))
    cout<<"yes,found";
    else
    cout<<"not found";
    
    return 0;
}