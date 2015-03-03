#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode() { left = right = NULL; }
    TreeNode(int _data);
};

TreeNode :: TreeNode(int _data)
{
    data = _data;
    left = right = NULL;
}

class Tree
{
    TreeNode *root;
    int rec_add_greater(TreeNode *);
    void rec_inorder(TreeNode *);
public:
    void build_bst(int *array, int size);
    void add_greater();
    void inorder() { rec_inorder(root); };
};

void Tree :: build_bst(int *element, int size)
{
    if (size == 0)
        root = NULL;

    root = new TreeNode(element[0]);
    TreeNode *curr, *prev;

    for (int i = 1; i < size; ++i) {
        curr = root;
        while (curr) {
            prev = curr;
            curr = (element[i] <= curr->data ? curr->left : curr->right);
        }
        if (element[i] <= prev->data)
            prev->left = new TreeNode(element[i]);
        else
            prev->right = new TreeNode(element[i]);
    }
}

void Tree :: add_greater()
{
    rec_add_greater(root);
}

int Tree :: rec_add_greater(TreeNode *root)
{
    if (!root)
        return 0;

    int orig_data = root->data;
    int left_sum = rec_add_greater(root->left);
    if (root->right) {
        root->data = rec_add_greater(root->right);
        return (orig_data + left_sum + root->data);
    }
    return (orig_data + left_sum);
}

void Tree :: rec_inorder(TreeNode *root)
{
    if (root) {
        rec_inorder(root->left);
        cout << root->data << " ";
        rec_inorder(root->right);
    }
}


int main(int argc, char *argv[])
{
    int element[50], size;
    Tree pine;

    cout << "Number of elements: ";
    cin >> size;
    for (int i = 0; i < size; ++i)
        cin >> element[i];

    pine.build_bst(element, size);
    pine.add_greater();
    pine.inorder();
    cout << endl;

    return 0;
}
