template <typename T>           /* File: bst-remove.cpp */
void BST<T>::remove(const T& x) // leftmost item of its right subtree
{
    if (is_empty())             // Item is not found; do nothing
        return;
    
    if (x < root->value)        // Remove from the left subtree
        root->left.remove(x);
    else if (x > root->value)   // Remove from the right subtree
        root->right.remove(x);
    else if (root->left.root && root->right.root) // Found node has 2 children
    {
        root->value = root->right.find_min(); // operator= defined?
        root->right.remove(root->value);
    }
    else                        // Found node has 0 or 1 child
    {
        bst_node* deleting_node = root; // Save the root to delete first
        root = (root->left.is_empty()) ? root->right.root : root->left.root;

        // Reset its left/right subtree to null first before removal
        deleting_node->left.root = deleting_node->right.root = NULL;
        delete deleting_node;
    }
}
