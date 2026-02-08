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
        Tree *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Tree *myleft, *myright;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Tree(l);
        if (r == -1)
            myright = NULL;
        else
            myright = new Tree(r);

        p->left = myleft;
        p->right = myright;

        if (p->left != NULL)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void print_left(Tree *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        print_left(root->left);
    }
    else if (root->right)
    {
        print_left(root->right);
    }
    cout << root->val << " ";
}
void print_right(Tree *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    if (root->right)
    {
        print_right(root->right);
    }
    else if (root->left)
    {
        print_right(root->left);
    }
}

int main()
{
    Tree *root = input_tree();

    if (root == NULL)
        return 0;

    print_left(root->left);
    cout << root->val << " ";
    print_right(root->right);

    return 0;
}