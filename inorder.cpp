#include<bits/stdc++.h>
using namespace std;
class Tree
{
    public:
int val;
Tree* Left;
Tree* Right;
Tree(int val)
{
    this->val=val;
    this->Left=NULL;
    this->Right=NULL;
}

};

void inorder(Tree* root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->Left);
    cout<<root->val<<" ";
    inorder(root->Right);
}
int main()
{
    Tree* root = new Tree(10);
    Tree* a = new Tree(20);
    Tree* b = new Tree(30);
    Tree* c = new Tree(40);
    Tree* d = new Tree(50);
    Tree* e = new Tree(60);
    

    root->Left = a;
    a->Left = c;
    root->Right=b;
    b->Left=d;
    b->Right = e;

    inorder(root);
    
    return 0;
}
