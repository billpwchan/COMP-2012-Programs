/*
 * avl.cpp
 */

#ifndef AVL_CPP
#define AVL_CPP



/* TODO
 * Goal: To find the balance factor of an AVL tree
 *       balance factor = height of right sub-tree - height of left sub-tree
 * Return: (int) balance factor
 */
template <typename T, typename K>
int AVL<T, K>::bfactor() const
{
	if (this->is_empty()) {
		return 0;
	} else {
		int left_avl_height = -1;
		int right_avl_height = -1;
		if (this->left_subtree() != NULL && dynamic_cast<const AVL<T, K>*>(this->left_subtree())->root != NULL)
			left_avl_height = dynamic_cast<const AVL<T, K>*>(this->left_subtree())->root->bt_height;
		if (this->right_subtree() != NULL && dynamic_cast<const AVL<T, K>*>(this->right_subtree())->root != NULL)
			right_avl_height = dynamic_cast<const AVL<T, K>*>(this->right_subtree())->root->bt_height;
		return right_avl_height - left_avl_height;
	}

}


/* TODO
 * Goal: To rectify the height values of each node of of an AVL tree
 */
template <typename T, typename K>
void AVL<T, K>::fix_height() const
{
	if (!this->is_empty()) {

		int left_avl_height = -1;
		int right_avl_height = -1;
		if (this->left_subtree() != NULL && dynamic_cast<const AVL<T, K>*>(this->left_subtree())->root != NULL)
			left_avl_height = dynamic_cast<const AVL<T, K>*>(this->left_subtree())->root->bt_height;
		if (this->right_subtree() != NULL && dynamic_cast<const AVL<T, K>*>(this->right_subtree())->root != NULL)
			right_avl_height = dynamic_cast<const AVL<T, K>*>(this->right_subtree())->root->bt_height;
		this->root->bt_height = 1 + max(left_avl_height, right_avl_height);
	}
}


/* TODO
 * Goal: To perform a single left (anti-clocwise) rotation of the root
 */
template <typename T, typename K>
void AVL<T, K>::rotate_left()
{
	AVL<T, K>* temp = dynamic_cast<AVL<T, K>*>(this->right_subtree());
	this->root->right = dynamic_cast<AVL<T, K>*>(temp->root->left);
	this->fix_height();
	bt_node* temp_node = this->root;
	this->root = temp->root;
	temp->root = temp_node;
	this->root->left = temp;
	this->fix_height();
}


/* TODO
 * Goal: To perform right (clockwise) rotation of the root
 */
template <typename T, typename K>
void AVL<T, K>::rotate_right()
{
	AVL<T, K>* temp = dynamic_cast<AVL<T, K>*>(this->left_subtree());
	this->root->left = dynamic_cast<AVL<T, K>*>(temp->root->right);
	this->fix_height();
	bt_node* temp_node = temp->root;
	temp->root = this->root;
	this->root = temp_node;
	this->root->right = temp;
	this->fix_height();
}

/* TODO
 * Goal: To balance an AVL tree
 */
template <typename T, typename K>
void AVL<T, K>::balance()
{
	if (this->is_empty())
		return;
	this->fix_height();
	int balance_factor = this->bfactor();
	if (balance_factor == 2) {
		if (this->right_subtree() != NULL && dynamic_cast<AVL<T, K>*>(this->right_subtree())->bfactor() < 0)
			dynamic_cast<AVL<T, K>*>(this->right_subtree())->rotate_right();
		return this->rotate_left();
	} else if (balance_factor == -2) {
		if (this->left_subtree() != NULL && dynamic_cast<AVL<T, K>*>(this->left_subtree())->bfactor() > 0)
			dynamic_cast<AVL<T, K>*>(this->left_subtree())->rotate_left();
		return this->rotate_right();
	}

}


/* TODO
 * Goal: To insert an item x with key k to AVL tree
 */
template <typename T, typename K>
void AVL<T, K>::insert(const T& x, const K& k)
{
	if (this->is_empty()) {
		this->root = new bt_node(x, k);
	} else if (k < this->root->key) {
		if (!this->left_subtree())
			this->left_subtree() = new AVL<T, K>;
		this->left_subtree()->insert(x, k);
	}
	else if (k > this->root->key) {
		if (!this->right_subtree())
			this->right_subtree() = new AVL<T, K>;
		this->right_subtree()->insert(x, k);
	}

	this->balance();
}



/* TODO
 * Goal: To remove an item with key k in AVL tree
 */
template <typename T, typename K>
void AVL<T, K>::remove(const K& k)
{
	if (this->is_empty())
		return;
	if (k < this->root->key && this->left_subtree() != NULL)
		this->left_subtree()->remove(k);
	else if (k > this->root->key && this->right_subtree() != NULL)
		this->right_subtree()->remove(k);
	else {
		if (this->left_subtree() == NULL && this->right_subtree() == NULL) {
			this->root->left = this->root->right = NULL;
			delete this->root;
			this->root = NULL;
		} else if (this->left_subtree() == NULL) {
			bt_node* temp_node = this->root;
			this->root = dynamic_cast<AVL<T, K>*>(this->right_subtree())->root == NULL ? NULL : dynamic_cast<AVL<T, K>*>(this->right_subtree())->root;
			temp_node->left = temp_node->right = NULL;
			delete temp_node;
			temp_node = NULL;
		} else if (this->right_subtree() == NULL) {
			bt_node* temp_node = this->root;
			this->root = dynamic_cast<AVL<T, K>*>(this->left_subtree())->root == NULL ? NULL : dynamic_cast<AVL<T, K>*>(this->left_subtree())->root;
			temp_node->left = temp_node->right = NULL;
			delete temp_node;
			temp_node = NULL;
		} else {
			AVL<T, K>* right_min = dynamic_cast<AVL<T, K>*>(this->right_subtree()->find_min());
			this->root->value = right_min -> root->value;
			this->root->key = right_min -> root->key;
			this->root->bt_height = right_min -> root->bt_height;
			this->right_subtree()->remove(this->root->key);
		}
	}
	this->balance();

}



#endif /* AVL_CPP */
