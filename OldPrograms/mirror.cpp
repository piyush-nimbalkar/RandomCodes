// Mirror a tree


#include <iostream>

using namespace std;

class TreeNode
{
public:
    int info;
    TreeNode *left;
    TreeNode *right;

    TreeNode() { left = right = NULL; }
    TreeNode(int);
};


TreeNode :: TreeNode(int value)
{
    info = value;
    left = right = NULL;
}


class Tree
{
public:
    TreeNode * mirror(TreeNode *);
};


TreeNode * Tree :: mirror(TreeNode * root)
{
    if (!root)
        return NULL;
    TreeNode mirror_root = new TreeNode(root -> data);
    mirror_root -> right = mirror(root -> left);
    mirrot_root -> left = mirror(root -> right);
    return mirror_root;
}
