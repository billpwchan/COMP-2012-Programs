#include "btree.h"      /* File: btree-test.cpp */
#include "btree-inorder.cpp"
#include "btree-preorder.cpp"
#include "btree-postorder.cpp"

template <typename T>
void print(Btree_node<T>* r) { cout << r->get_data() << endl; }

int main() // Build the tree from bottom up
{   // Create the left subtree
    Btree_node<int>* node5 = new Btree_node<int>(5);
    Btree_node<int>* node9 = new Btree_node<int>(9);
    Btree_node<int>* node8 = new Btree_node<int>(8, node5, node9);
    // Create the right subtree
    Btree_node<int>* node12 = new Btree_node<int>(12);
    Btree_node<int>* node17 = new Btree_node<int>(17);
    Btree_node<int>* node15 = new Btree_node<int>(15, node12, node17);
    // Create the root node
    Btree_node<int>* root = new Btree_node<int>(10, node8, node15);

    cout << "\nInorder traversal result:\n"; btree_inorder(root, print);
    cout << "\nPreorder traversal result:\n"; btree_preorder(root, print);
    cout << "\nPostorder traversal result:\n"; btree_postorder(root, print);
    cout << "\nDeleting the binary tree ...\n"; delete root; return 0;
}
