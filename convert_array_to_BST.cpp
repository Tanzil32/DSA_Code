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

void level_order(Tree* root)
{
    queue<Tree*> q;
    q.push(root);
    while (!q.empty())
    {
        Tree* f = q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->Left!=NULL)
        q.push(f->Left);
        if(f->Right!=NULL)
        q.push(f->Right);
    }  
}
Tree* convert(int a[],int n,int l,int r)
{
    if(l>r)
    return NULL;
    int mid = (l+r)/2;
    Tree* root = new Tree(a[mid]);
    Tree* Leftroot = convert(a,n,l,mid-1);
    Tree* Rightroot = convert(a,n,mid+1,r); 
    root->Left=Leftroot;
    root->Right=Rightroot;
    return root;


} 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    Tree* root = convert(a,n,0,n-1);
    level_order(root);

    
    return 0;
}