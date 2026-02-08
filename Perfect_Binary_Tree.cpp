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
    if(val == -1) 
    return NULL;
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

       p->Left=myleft;
       p->Right=myright;

       if(p->Left!=NULL)
       q.push(p->Left);
       if(p->Right)
       q.push(p->Right);


    }
    return root;

}
bool Perfect_Binary_Tree(Tree* root)
{
    vector<int> v;
    if(root==NULL)
    {
        return true;
    }
    queue<pair<Tree* ,int>> q;
    if(root)
    q.push({root,0});
    int leaflevel=0;
    while (!q.empty())
    {
        pair<Tree* ,int> f = q.front();
        q.pop();
        Tree* parent = f.first;
        int level = f.second;
        if((parent->Left!=NULL && parent->Right==NULL)||(parent->Left==NULL && parent->Right!=NULL))
        return false;
        if(parent->Left==NULL && parent->Right==NULL)
        {
             if(leaflevel == 0)
                leaflevel = level;
            else if(level != leaflevel)
                return false;

        }

       
        if(parent->Left)
        q.push({parent->Left,level+1});
        if(parent->Right)
        q.push({parent->Right,level+1});
    }
   return true;
}

int main()
{
   Tree* root = input_tree();
   if(Perfect_Binary_Tree(root))
        cout << "YES";
    else
        cout << "NO";
   
    return 0;
}
