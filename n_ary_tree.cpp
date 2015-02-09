#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NUM = 6;

class TreeNode
{
public:
    int data;
    TreeNode *children[NUM];
    TreeNode() {}
    TreeNode(int data);
};

TreeNode :: TreeNode(int info)
{
    data = info;
    for (int i = 0; i < NUM; ++i)
        children[i] = NULL;
}

class Tree
{
    TreeNode *root;
    int rec_weighted_height(TreeNode *);
    int rec_iteration_count(TreeNode *);
public:
    Tree() { root = NULL; };
    void build_tree();
    void display_tree();
    void calc_information_time();
};

void Tree :: build_tree()
{
    int value, i;
    TreeNode *current_node;
    queue<TreeNode *> q;

    cout << "Enter root: ";
    cin >> value;
    root = new TreeNode(value);

    q.push(root);
    while(!q.empty()) {
        current_node = q.front();
        q.pop();
        cout << "Enter children for " << current_node->data << " : ";
        for (i = 0; i < NUM; i++) {
            cin >> value;
            if (value == -1)
                break;
            current_node->children[i] = new TreeNode(value);
            q.push(current_node->children[i]);
        }
    }
}

void Tree :: display_tree()
{
    int i;
    TreeNode *current_node, *delimiter;
    queue<TreeNode *> q;

    delimiter = new TreeNode(-1);
    q.push(root);
    q.push(delimiter);
    while(!q.empty()) {
        current_node = q.front();

        if (current_node == delimiter) {
            cout << endl;
            q.pop();
            q.push(delimiter);
        }

        if (q.size() == 1 && q.front() == delimiter)
            break;

        current_node = q.front();
        cout << current_node->data << " ";
        q.pop();

        for (i = 0; i < NUM && current_node->children[i]; i++)
            q.push(current_node->children[i]);
    }
}

int Tree :: rec_weighted_height(TreeNode *root)
{
    int i, max = -1, current_height;

    if (!root)
        return 0;

    for (i = 0; i < NUM && root->children[i]; i++) {
        current_height = rec_weighted_height(root->children[i]) + i;
        if (max < current_height) {
            max = current_height;
        }
    }
    return max + 1;
}

int Tree :: rec_iteration_count(TreeNode *root)
{
    int i, max = -1, current_height;
    vector<int> child_iterations;

    if (!root)
        return 0;

    for (i = 0; i < NUM && root->children[i]; i++)
        child_iterations.push_back(rec_iteration_count(root->children[i]));

    sort(child_iterations.begin(), child_iterations.end(), greater<int>());

    for (i = 0; i < child_iterations.size(); i++)
        if (max < (child_iterations[i] + i))
            max = child_iterations[i] + i;

    return max + 1;
}

void Tree :: calc_information_time()
{
    // cout << "Iterations required: " << rec_weighted_height(root) << endl;
    cout << "Iterations required: " << rec_iteration_count(root) << endl;
}


int main(int argc, char *argv[])
{
    Tree mango;

    mango.build_tree();
    mango.display_tree();
    mango.calc_information_time();

    return 0;
}
