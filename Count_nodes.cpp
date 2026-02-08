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
       myright= new Tree(l);

       p->Left=myleft;
       p->Right=myright;

       if(p->Left!=NULL)
       q.push(p->Left);
       if(p->Right)
       q.push(p->Right);


    }
    return root;

}

int count_nodes(Tree* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int l= count_nodes(root->Left);
    int r = count_nodes(root->Right);
    return l+r+1;
}

// void level_order(Tree* root)
// {
//     queue<Tree*> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Tree* f = q.front();
//         q.pop();
//         cout<<f->val<<" ";
//         if(f->Left!=NULL)
//         q.push(f->Left);
//         if(f->Right!=NULL)
//         q.push(f->Right);
//     }
    
   
// }
int main()
{
   Tree* root = input_tree();

    // 
    cout<<count_nodes(root);
    
    return 0;
}
