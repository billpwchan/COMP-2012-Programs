/*
 * bt.cpp
 *
 */

#ifndef BT_CPP
#define BT_CPP


/* TODO
 * Goal: Do preorder traversal on the tree
 * Remark: print both value and key fields of each node
 */

//This is actually an infix transverse
template <typename T, typename K>
void BT<T, K>::preorder_traversal() const
{

	if (!this->is_empty()) {
		cout << "Key: " << this->root->key << "        Value: " << this->root->value << endl;
		if (this->root->left != NULL && this->root->left->root != NULL)
			this->root->left->preorder_traversal();
		if (this->root->right != NULL && this->root->right->root != NULL)
			this->root->right->preorder_traversal();
	}

}



#endif /* BT_CPP */
