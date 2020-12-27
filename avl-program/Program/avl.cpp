 /* Goal: To find the height of an AVL tree
 * Return: (int) tree's height
 */

template <typename T>
int AVL<T>::height() const
{
    return empty() ? -1 : root->height;
}

/* Goal: To find the balance factor of an AVL tree
 *       balance factor = height of right sub-tree - height of left sub-tree
 * Return: (int) balance factor
 */

template <typename T>
int AVL<T>::bfactor() const
{
    cout <<( empty() ? 0 : right_subtree().height() - left_subtree().height())<<endl;
    return empty() ? 0 : right_subtree().height() - left_subtree().height();
}


/* Goal: To rectify the height values of each node of of an AVL tree */ 

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


/* Goal: To perform a single left (anti-clocwise) rotation */

template <typename T>
void AVL<T>::rotate_left() // The calling AVL node is node a
{
    AVL_node* b = right_subtree().root; // Points to node b
    right_subtree() = b->left;
    b->left = *this;    // Note: *this is node a
    fix_height();       // Fix the height of node a
    this->root = b;     // Node b becomes the new root
    fix_height();       // Fix the height of node b, now root of the whole AVL
}


/* Goal: To perform right (clockwise) rotation */
template <typename T>
void AVL<T>::rotate_right() // The calling AVL node is node a
{
    AVL_node* b = left_subtree().root; // Points to node b
    left_subtree() = b->right;
    b->right = *this;   // Note: *this is node a
    fix_height();       // Fix the height of node a
    this->root = b;     // Node b becomes the new root
    fix_height();       // Fix the height of node b, now root of the whole AVL
}



/* Goal: To balance an AVL tree */

template <typename T>
void AVL<T>::balance()
{
    if (empty())
        return;
    
    fix_height();
    int balance_factor = bfactor();

    if (balance_factor == 2)       // Right subtree is taller by 2
    {
        if (right_subtree().bfactor() < 0) // Case 2: insertion to the L of RT
            right_subtree().rotate_right();

        return rotate_left();      // Cases 1 or 2: Insertion to the R/L of RT
    }

    else if (balance_factor == -2) // Left subtree is taller by 2
    {
        if (left_subtree().bfactor() > 0) // Case 4: insertion to the R of LT
            left_subtree().rotate_left();

        return rotate_right();     // Cases 3 or 4: insertion to the L/R of LT
    }
    // Balancing is not required for the remaining cases
}


/* Goal: To find the minimum value stored in an AVL tree.
 * Return: The minimum value
 */

template <typename T>
const T& AVL<T>::find_min() const
{
    const AVL& left_avl = left_subtree();
    
    if (left_avl.empty())
        return root->value;

    return left_avl.find_min();
}


/* Goal: To insert an item x to AVL tree 
 * Return: Balanced tree
 */

template <typename T>
void AVL<T>::insert(const T& x)
{
    if (empty())                   // Start with an empty AVL tree
        root = new AVL_node(x);
    
    else if (x < root->value)
        left_subtree().insert(x);  // Recursion on the left sub-tree

    else if (x > root->value)
        right_subtree().insert(x); // Recursion on the left sub-tree

    balance();
}



/* Goal: To remove an item x in AVL tree */

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

        if (!left_avl.empty() && !right_avl.empty())
        {   // Found node has 2 children 
            root->value = right_avl.find_min(); // Copy the min. value
            right_avl.remove(root->value);      // Remove node with min. value
        }
        else // Found node has 0 or 1 child
        {
            AVL_node* node_to_remove = root;  // Save the node to be removed
            *this = left_avl.empty() ? right_avl : left_avl;

            // Reset the node to be removed with empty children
            right_avl.root = left_avl.root = NULL;
            delete node_to_remove;
        }
    }

    balance();
}



/* Goal: To search for an item x in an AVL tree
 * Return: (bool) true / false
 */

template <typename T>
bool AVL<T>::contains(const T& x) const
{
    if (empty())
      return false;

    else if (x == root->value)
      return true;

   else if (x < root->value)
       return left_subtree().contains(x);

   else
       return right_subtree().contains(x);
}

/* Goal: To print an AVL tree 
 * Remark: The output is the AVL tree that is rotated -90 degrees
 */

template <typename T>
void AVL<T>::print(int depth) const
{
    if (empty())
      return;

    right_subtree().print(depth+1); // Recursion on the right sub-tree

    for(int j = 0; j < depth; j++) // Print the node value
        cout << '\t';
    cout << root->value << endl;

    left_subtree().print(depth+1); // Recursion on the left sub-tree
}
