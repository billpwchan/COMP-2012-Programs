/* Goal: To perform a single left (anti-clocwise) rotation */
template <typename T>
void AVL<T>::rotate_left() // The calling AVL node is node a
{
    AVL_node* b = right_subtree().root; // Points to node b
    right_subtree() = b->left;
    b->left = *this;    // Note: *this is node a
    fix_height();       // Fix the height of node a
    this->root = b;     // Node b becomes the new root
    fix_height();       // Fix the height of node b, now the new root
}
