/* File: btree-preorder.cpp
 *
 * To traverse a binary tree in the order of:
 *    node, left subtree, right subtree
 * and do some action on each node during the traversal.
 */

template <class T>
void btree_preorder(Btree_node<T>* root,
     void (*action)(Btree_node<T>* r)) // Expect a function on r->data
{
    if (root)
    {
        action(root);   // e.g. print out root->data
        btree_preorder(root->get_left(), action);
        btree_preorder(root->get_right(), action);
    }
}

