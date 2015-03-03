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
    void print_kth_rec(vector<int> &memo, TreeNode *current, int k);
public:
    void build_bst(int *array, int size);
    void print_kth_backwards();
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

void Tree :: print_kth_backwards()
{
    vector<int> memo;
    print_kth_rec(memo, root, 2);
}

void Tree :: print_kth_rec(vector<int> &memo, TreeNode *current, int k)
{
    if (!current->left && !current->right && memo.size() >= k)
            cout << memo.at(memo.size() - k) << endl;

    memo.push_back(current->data);

    if (current->left)
        print_kth_rec(memo, current->left, k);

    if (current->right)
        print_kth_rec(memo, current->right, k);

    memo.pop_back();
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

    pine.print_kth_backwards();

    return 0;
}
