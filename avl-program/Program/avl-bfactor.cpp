/* balance factor = height of right sub-tree - height of left sub-tree */
template <typename T>
int AVL<T>::bfactor() const
{
    return empty() ? 0 : right_subtree().height() - left_subtree().height();
}
