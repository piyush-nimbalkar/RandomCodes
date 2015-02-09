// Write C++ code to return a pointer to the nth node of an inorder traversal of a BST

#include<iostream>

using namespace std;

class TreeNode
{
public:
    int info;
    TreeNode *left;
    TreeNode *right;

    TreeNode();
};

TreeNode :: TreeNode()
{
    left = right = NULL;
}

class Tree
{
public:
    TreeNode * nth_inorder(TreeNode *, int);
}

TreeNode * TreeNode :: nth_inorder(TreeNode * root, int node_number, int &count)
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

int main()
{
    TreeNode *root = some_bst();
    Tree tree;

    int node_number_to_be_found = 10;
    int count = 0;

    tree.nth_inorder(root, node_number_to_be_found, count);
    return 0;
}








// ********************************************************************

// java

// return the nth node of inorder traversal of BST


// public class Node{
    // public int data;
    // public Node left;
    // public Node right;
// }

// public class Traversal{
    // public static int count =0;
    // public Node inorderNthNode(Node node, int nodeNumber){
        // Node result = null;
        // if(node == null)
            // return null;
        // if(result = inorderNthNode(node.left, nodeNumber))
            // return result;
        // count++;
        // if(count == nodeNumber)
            // return node;
        // if(result = inorderNthNode(node.right, nodeNumber))
            // return result;
        // return result;
    // }

    // public static void main(){
        // Traversal t = new Traversal();
        // input for tree
        // Node root = constructTree();
        // System.out.println(t.inorderNthNode(root, 5).data);
    // }
// }
