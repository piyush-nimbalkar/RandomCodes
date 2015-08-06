// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.

struct Node {
    char ch;
    Node* left;
    Node* right;
}

static char getKthChar(Node* root, int k) {
   map<Node *, int> hash;
   return rec_getKth(root, k, hash);
}

char rec_getKth(Node * root, int k, map<Node *, int> hash)
{
    char c;
    int left = 0, right = 0;

    if (hash.count(root->left) < 1 && root->left)
        rec_getKth(root->left, k, hash);

    if (root->left)
        left = hash[root->left];

    if (left+1 == k)
        return root->ch;

    if (hash.count(root->right) < 1 && root->right)
        right = rec_getKth(root->right, k-left-1, hash);

    if (root->right)
        right = hash[root->right];

    hash[root] = left + right + 1;
}



         // 012
   // A     bac
  // / \
  // B  C n = 3

   // 012
// A  bab
// ||
// B n = 2

// A
// ||
// B
// ||
// C

// 0123456
// CBCACBC


// (2^n) - 1 == 2^0 + 2^1 + 2^2 + ....
