/* Goal: To perform right (clockwise) rotation */
template <typename T>
void AVL<T>::rotate_right() // The calling AVL node is node a
{
    AVL_node* b = left_subtree().root; // Points to node b
    left_subtree() = b->right;
    b->right = *this;   // Note: *this is node a
    fix_height();       // Fix the height of node a
    this->root = b;     // Node b becomes the new root
    fix_height();       // Fix the height of node b, now the new root
}
