#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;



class TreeNode
{
public:
    int info;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
    TreeNode(int);
    void set_left(int);
    void set_right(int);
};

typedef stack<TreeNode *> Stack;
typedef queue<TreeNode *> Queue;

TreeNode :: TreeNode()
{
    left = right = NULL;
}

TreeNode :: TreeNode(int value)
{
    info = value;
    left = right = NULL;
}

void TreeNode :: set_left(int value)
{
    left = new TreeNode(value);
}

void TreeNode :: set_right(int value)
{
    right = new TreeNode(value);
}

TreeNode * build_bst(int *array, int size)
{
    if (size == 0)
        return NULL;
    TreeNode *root = new TreeNode(array[0]);
    TreeNode *p = root, *prev;

    for(int i = 1; i < size; i++) {
        p = root;
        while(p != NULL) {
            prev = p;
            p = (array[i] <= p -> info) ? (p -> left) : (p -> right);
        }
        if(array[i] <= prev -> info)
            prev -> set_left(array[i]);
        else
            prev -> set_right(array[i]);
    }
    return root;
}

void inorder(TreeNode *root)
{
    if(root) {
        inorder(root -> left);
        cout << root -> info << " ";
        inorder(root -> right);
    }
}

void preorder(TreeNode *root)
{
    if(root) {
        cout << root -> info << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder(TreeNode *root)
{
    if(root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> info << " ";
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(TreeNode *root)
{
    if(root)
        return max(height(root -> left), height(root -> right)) + 1;
    return 0;
}

int is_balanced(TreeNode *root)
{
    if(!root)
        return 0;

    int left = is_balanced(root -> left);
    int right = is_balanced(root -> right);

    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    return abs(left - right) + 1;
}

void generate_lists(TreeNode *root)
{
    int level = 0;
    vector<TreeNode> list[10];
    list[level].push_back(*root);
    while(true) {
        for(vector<TreeNode> :: iterator it = list[level].begin(); it != list[level].end(); it++) {
            if(it->left)
                list[level + 1].push_back(*(*it).left);
            if((it->right)
                list[level + 1].push_back(*(*it).right);
        }
        level++;
        if(list[level].empty())
            break;
    }
    for(int i = 0; i < level; i++) {
        for(vector<TreeNode> :: iterator it = list[i].begin(); it != list[i].end(); it++)
            cout << it -> info << " ";
        cout << endl;
    }
}

TreeNode * nth_inorder(TreeNode * root, int node_number, int &count)
{
    TreeNode * node = NULL;
    if(root) {
        if(node = nth_inorder(root -> left, node_number, count))
            return node;
        if (++count == node_number)
            return root;
        if(node = nth_inorder(root -> right, node_number, count))
            return node;
    }
    return node;
}

void iterative_preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *node;
    Stack s;
    s.push(root);
    while(!s.empty()) {
        node = s.top();
        s.pop();
        if (node->right != NULL)
            s.push(node->right);
        if (node->left != NULL)
            s.push(node->left);
        cout << node->info << " ";
    }
}

void iterative_inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    Stack s;
    TreeNode *node = root;
    while(node != NULL || !s.empty()) {
        if (node != NULL) {
            s.push(node);
            node = node->left;
        }
        else {
            node = s.top();
            s.pop();
            cout << node->info << " ";
            node = node->right;
        }
    }
}

void iterative_postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    Stack s;
    TreeNode *temp, *node = root;
    while(true) {
        if (node != NULL) {
            if (node->right != NULL)
                s.push(node->right);
            s.push(node);
            node = node->left;
            continue;
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
            cout << node->info << " ";
            node = NULL;
        }
    }
}

void print_level_order(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->info << " ";
    else {
        print_level_order(root->left, level - 1);
        print_level_order(root->right, level - 1);
    }
}

void level_order(TreeNode *root)
{
    if (root == NULL)
        return;
    int ht = height(root);
    for (int i = 1; i <= ht; i++) {
        print_level_order(root, i);
        cout << endl;
    }
}

void iterative_level_order(TreeNode *root)
{
    if (root == NULL)
        return;
    Queue q;
    TreeNode *delimeter = new TreeNode(999);
    TreeNode *node = root;
    q.push(root);
    q.push(delimeter);
    while(!q.empty() && q.front() != delimeter) {
        while((node = q.front()) != delimeter) {
            q.pop();
            cout << node->info << " ";
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        q.pop();
        cout << endl;
        if (!q.empty())
            q.push(delimeter);
    }
}

int main(int argc, char *argv[])
{
    int size = 9;
    int array[size], i;
    for(i = 0; i < size; i++)
        cin >> array[i];

    TreeNode *root = build_bst(array, size);

    iterative_level_order(root);

    // level_order(root);

    // iterative_postorder(root);
    // cout << endl;

    // iterative_preorder(root);
    // cout << endl;

    // iterative_inorder(root);
    // cout << endl;

    // inorder(root);
    // cout << endl;

    // generate_lists(root);

    // int node_number_to_be_found = 5;
    // int count = 0;
    // nth_inorder(root, node_number_to_be_found, count);
}
