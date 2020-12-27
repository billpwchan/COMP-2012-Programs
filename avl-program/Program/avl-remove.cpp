/* To remove an item x in AVL tree and keep the tree balanced */

template <typename T>
void AVL<T>::remove(const T& x)
{
    if (empty())        // Item is not found; do nothing
        return;

    if (x < root->value)
        left_subtree().remove(x);  // Recursion on the left sub-tree

    else if (x > root->value)
        right_subtree().remove(x); // Recursion on the right sub-tree

    else
    {
        AVL& left_avl = left_subtree();
        AVL& right_avl = right_subtree();

        // Found node has 2 children 
        if (!left_avl.empty() && !right_avl.empty())
        {
            root->value = right_avl.find_min(); // Copy the min value
            right_avl.remove(root->value); // Remove node with min value
        }

        else  // Found node has 0 or 1 child
        {
            AVL_node* node_to_remove = root; // Save the node first
            *this = left_avl.empty() ? right_avl : left_avl;

            // Reset the node to be removed with empty children
            right_avl.root = left_avl.root = NULL;
            delete node_to_remove;
        }
    }

    balance(); // Re-balance the tree at every visited node
}
