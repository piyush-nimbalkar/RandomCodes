// Closest ancestor

TreeNode * common_ancestor(TreeNode *root, TreeNode *first, TreeNode *second)
{
    TreeNode *p1, *p2;

    if (is_ancestor(root -> left, first) && is_ancestor(root -> left, second))
        return common_ancestor(root -> left, first, second);

    if (is_ancestor(root -> right, first) && is_ancestor(root -> right, second))
        return common_ancestor(root -> right, first, second);

    return root;
}

bool is_ancestor(TreeNode *root, TreeNode *node)
{
    if (root && root == node || is_ancestor(root -> left, node) || is_ancestor(root -> right, node))
        return true;
    return false;
}
