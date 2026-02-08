#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;

    Tree(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Tree *input_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    Tree *root = new Tree(val);
    queue<Tree *> q;
    q.push(root);

    while (!q.empty())
    {
        Tree *f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
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
vector<int> Leaf_Nodes_reverse(Tree *root)
{
    vector<int> v;
    if (root == NULL)
        return {};

    queue<Tree *> q;
    q.push(root);

    while (!q.empty())
    {
        Tree *f = q.front();
        q.pop();
        if (f->left == NULL && f->right == NULL)
        {
            v.push_back(f->val);
        }

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }

    sort(v.begin(), v.end(), greater<int>());
    return v;
}

int main()
{
    Tree *root = input_tree();
    vector<int> ans = Leaf_Nodes_reverse(root);

    for (int x : ans)
    {
        cout << x << " ";
    }
    return 0;
}
