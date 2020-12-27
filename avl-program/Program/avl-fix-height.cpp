/* Goal: To rectify the height values of each AVL node */
template <typename T>
void AVL<T>::fix_height() const
{
    if (!empty())
    {
        int left_avl_height = left_subtree().height();
        int right_avl_height = right_subtree().height();
        root->height = 1 + max(left_avl_height, right_avl_height);
    }
}
