/* To find the height of an AVL tree */
template <typename T>
int AVL<T>::height() const { return empty() ? -1 : root->height; }
