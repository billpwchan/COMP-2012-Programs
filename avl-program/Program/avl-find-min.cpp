/* To find the minimum value stored in an AVL tree. */

template <typename T>
const T& AVL<T>::find_min() const
{
    // It is assumed that the calling tree is not empty
    const AVL& left_avl = left_subtree();
    
    if (left_avl.empty())       // Base case: Found!
        return root->value;

    return left_avl.find_min(); // Recursion on the left subtree
}
