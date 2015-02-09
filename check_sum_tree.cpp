#include <iostream>

using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode() { left = right = NULL; }
    TreeNode(int);
    // ~TreeNode() { delete left; delete right; }
};

TreeNode :: TreeNode(int value)
{
    data = value;
    left = right = NULL;
}


class Tree
{
    TreeNode *root;
    bool rec_check_sum(TreeNode*, int, bool);
public:
    Tree() { root = NULL; };
    void build_bst(int *, int);
    void check_if_sum_exists(int);
    ~Tree() { delete root; };
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

bool Tree :: rec_check_sum(TreeNode *root, int sum, bool parent_included=true)
{
    if (!root || root->data > sum)
        return false;

    if (root->data == sum) {
        cout << root->data << " ";
        return true;
    }

    if (rec_check_sum(root->left, sum - root->data) || rec_check_sum(root->right, sum - root->data)) {
        cout << root->data << " ";
        return true;
    }

    if (!parent_included)
        return (rec_check_sum(root->left, sum, false) || rec_check_sum(root->right, sum, false));

    return false;
}

void Tree :: check_if_sum_exists(int sum)
{
    cout << "\nSum is " << (rec_check_sum(root, sum, false) ? "" : "not ") << "present" << endl;
}

int main(int argc, char *argv[])
{
    int element[50], size, sum;
    Tree pine;

    cout << "Number of elements: ";
    cin >> size;

    for (int i = 0; i < size; ++i)
        cin >> element[i];

    pine.build_bst(element, size);

    cout << "Enter sum to be checked: ";
    cin >> sum;

    pine.check_if_sum_exists(sum);

    return 0;
}
