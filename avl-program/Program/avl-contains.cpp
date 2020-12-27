// Goal: To search for an item x in an AVL tree
// Return: (bool) true if found, otherwise false
template <typename T>
bool AVL<T>::contains(const T& x) const
{
    if (empty())               // Base case #1
      return false;

    else if (x == root->value) // Base case #2
      return true;

    else if (x < root->value)   // Recursion on the left subtree
       return left_subtree().contains(x);

   else                         // Recursion on the right subtree
       return right_subtree().contains(x);
}
