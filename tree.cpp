#include <iostream>
#include <stack>
#include <queue>

using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode() { left = right = NULL; }
    TreeNode(int);
    ~TreeNode() { delete left; delete right; }
};

TreeNode :: TreeNode(int value)
{
    data = value;
    left = right = NULL;
}


typedef stack<TreeNode *> Stack;
typedef queue<TreeNode *> Queue;


class Tree
{
    TreeNode *root;
    int rec_height(TreeNode *);
    void rec_inorder(TreeNode *);
    void rec_preorder(TreeNode *);
    void rec_postorder(TreeNode *);
    int max(int a, int b) { return (a > b ? a : b); }
public:
    Tree() { root = NULL; };
    void build_bst(int *, int);
    int height() { return rec_height(root); }

    void inorder() { rec_inorder(root); }
    void preorder() { rec_preorder(root); }
    void postorder() { rec_postorder(root); }

    void iterative_inorder();
    void iterative_preorder();
    void iterative_postorder();

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

int Tree :: rec_height(TreeNode *root)
{
    return (root ? (max(rec_height(root->left), rec_height(root->right)) + 1) : 0);
}

void Tree :: rec_preorder(TreeNode *root)
{
    if (root) {
        cout << root->data << " ";
        rec_preorder(root->left);
        rec_preorder(root->right);
    }
}

void Tree :: rec_inorder(TreeNode *root)
{
    if (root) {
        rec_inorder(root->left);
        cout << root->data << " ";
        rec_inorder(root->right);
    }
}

void Tree :: rec_postorder(TreeNode *root)
{
    if (root) {
        rec_postorder(root->left);
        rec_postorder(root->right);
        cout << root->data << " ";
    }
}

void Tree :: iterative_preorder()
{
    if (!root)
        return;

    Stack s;
    TreeNode *node;

    s.push(root);
    while(!s.empty()) {
        node = s.top();
        s.pop();
        if (node->right)
            s.push(node->right);
        if (node->left)
            s.push(node->left);
        cout << node->data << " ";
    }
}

void Tree :: iterative_inorder()
{
    if (!root)
        return;

    Stack s;
    TreeNode *node = root;

    while(node || !s.empty()) {
        if (node) {
            s.push(node);
            node = node->left;
        } else {
            node = s.top();
            s.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

void Tree :: iterative_postorder()
{
    if (!root)
        return;

    Stack s;
    TreeNode *node = root;

    while(true) {
        while (node) {
            if (node->right)
                s.push(node->right);
            s.push(node);
            node = node->left;
        }
        if (s.empty())
            break;
        node = s.top();
        s.pop();
        if (!s.empty() && node->right == s.top()) {
            s.pop();
            s.push(node);
            node = node->right;
        } else {
            cout << node->data << " ";
            node = NULL;
        }
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

    // pine.inorder();
    // cout << endl;

    // pine.iterative_inorder();
    // cout << endl;

    // pine.preorder();
    // cout << endl;

    // pine.iterative_preorder();
    // cout << endl;

    pine.postorder();
    cout << endl;

    pine.iterative_postorder();
    cout << endl;

    // cout << pine.height();
    // cout << endl;

    return 0;
}
