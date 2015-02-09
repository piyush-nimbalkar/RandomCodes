#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode() { left = right = NULL; }
    TreeNode(int);
};

TreeNode :: TreeNode(int value)
{
    data = value;
    left = right = NULL;
}


class Tree
{
    TreeNode *root;
    void rec_max_sum(TreeNode *, int &, int);
    int rec_height(TreeNode *);
public:
    Tree() { root = NULL; };
    int height() { return rec_height(root); }
    void build_tree();
    void find_max_sum();
    void display_tree();
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
        cout << "Enter left and right children for " << current_node->data << " : ";
        cin >> value;
        if (value != -1) {
            current_node->left = new TreeNode(value);
            q.push(current_node->left);
        }
        cin >> value;
        if (value != -1) {
            current_node->right = new TreeNode(value);
            q.push(current_node->right);
        }
    }
}

int Tree :: rec_height(TreeNode *root)
{
    return (root ? (max(rec_height(root->left), rec_height(root->right)) + 1) : 0);
}

void Tree :: display_tree()
{
    int i, ht, tabs;
    TreeNode *current_node, *null_node, *delimiter;
    queue<TreeNode *> q;

    ht = height()-1;

    null_node = new TreeNode(-99999);
    null_node = new TreeNode(-1);
    q.push(root);
    q.push(delimiter);

    cout << endl << endl;
    for (i = ht; i >= 0; i--) {
        while ((current_node = q.front()) != delimiter) {
            for (tabs = pow(2, i); tabs > 1; tabs--)
                cout << "  ";
            if (current_node != null_node) {
                if (current_node->left)
                    q.push(current_node->left);
                else
                    q.push(null_node);

                if (current_node->right)
                    q.push(current_node->right);
                else
                    q.push(null_node);

                cout << setw(2) << current_node->data;
            } else {
                q.push(null_node);
                q.push(null_node);
                cout << "  ";
            }
            for (tabs = pow(2, i); tabs > 0; tabs--)
                cout << "  ";
            q.pop();
        }
        q.push(q.front());
        q.pop();
        cout << endl << endl;
    }
    cout << endl;
}

void Tree :: rec_max_sum(TreeNode *root, int &max_sum, int sum)
{
    if (!root)
        return;

    sum += root->data;
    if (sum > max_sum)
        max_sum = sum;

    sum = (sum <= 0 ? 0 : sum);
    rec_max_sum(root->left, max_sum, sum);
    rec_max_sum(root->right, max_sum, sum);
}

void Tree :: find_max_sum()
{
    int max_sum = -99999, sum = 0;
    rec_max_sum(root, max_sum, sum);
    cout << "\nMaximum Sum: " << max_sum << endl;
}


int main(int argc, char *argv[])
{
    Tree apple;

    apple.build_tree();
    apple.display_tree();
    apple.find_max_sum();

    return 0;
}
