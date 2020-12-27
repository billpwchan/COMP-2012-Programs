/*
 * bst.cpp
 *
 */

#ifndef BST_CPP
#define BST_CPP


/* TODO
 * Goal: To search for an item x with key k from the BST tree
 * Return: A pointer to the subtree whose root node contains the item if found,
 *         otherwise a NULL pointer.
 */
template <typename T, typename K>
BT<T, K>* BST<T, K>::search(const K& k)
{
	if (this->is_empty())
		return NULL;

	if (this->root->key == k) {
		return this;
	}
	//Need to revise
	if (this->left_subtree() != NULL && k < this->root->key)
		return this->left_subtree()->search(k);
	if (this->right_subtree() != NULL && k > this->root->key)
		return this->right_subtree()->search(k);
	return NULL;
}


/* TODO
 * Goal: To find the minimum node stored in a BST tree.
 * Return: A pointer to the subtree whose root node contains the minimum key
 */
template <typename T, typename K>
BT<T, K>* BST<T, K>::find_min()
{
	if (this->is_empty())
		return NULL;

	if (this->left_subtree() == NULL) {
		return this;
	}

	return this->left_subtree()->find_min();
}


/* TODO
 * Goal: To insert an item x with key k to a BST tree
 */
template <typename T, typename K>
void BST<T, K>::insert(const T& x, const K& k)
{
	//Need to make sure the declaration of the new node is correct! Check the scope and access-right.
	if (this->is_empty()) {
		this->root = new bt_node(x, k);
	}
	else if (k < this->root->key) {
		if (!this->left_subtree())
			this->left_subtree() = new BST<T, K>;
		this->left_subtree()->insert(x, k);
	} else if (k > this->root->key) {
		if (!this->right_subtree())
			this->right_subtree() = new BST<T, K>;
		this->right_subtree()->insert(x, k);
	}
}


/* TODO
 * Goal: To remove an item with key k in a BST tree
 */
// template <typename T, typename K>
// void BST<T, K>::remove(const K& k)
// {
// 	cout << "Now is going to remove!"<<endl;
// 	if (this->is_empty())
// 		return;
// 	if (k < this->root->key)
// 		{this->left_subtree()->remove(k);}
// 	else if (k > this->root->key)
// 		{this->right_subtree()->remove(k);}
// 	else if (this->left_subtree()!=NULL && this->right_subtree()!=NULL){
// 		//Require to check the destructor has correctly implemented. This has a lot of wrong
// 		// this->root = this->right_subtree()->find_min()->root;
// 		cout << "Going to crash!!"<<endl;
// 		BST<T, K>* right_min= dynamic_cast<BST<T, K>*>(this->right_subtree()->find_min());
// 		this->root = right_min->root;
// 		this->right_subtree()->remove(this->root->key);
// 	}else{
// 		cout << "Going to crash 2!!"<<endl;
// 		bt_node* deleting_node = this->root;
// 		if (this->left_subtree()==NULL && this->right_subtree()==NULL)
// 			this->root = NULL;
// 		else
// 			this->root = (this->left_subtree()->is_empty()?dynamic_cast<BST<T, K>*>(this->right_subtree())->root:dynamic_cast<BST<T, K>*>(this->left_subtree())->root);

// 		deleting_node->left = deleting_node->right = NULL;
// 		delete deleting_node;

// 	}
// }


// template <typename T, typename K>
// void BST<T, K>::remove(const K& k)
// {
// 	if (this->is_empty())
// 		return;
// 	if (k < this->root->key) {
// 		this->left_subtree()->remove(k);
// 	}
// 	else if (k > this->root->key) {
// 		this->right_subtree()->remove(k);
// 	}
// 	else if (this->left_subtree() == NULL && this->right_subtree() == NULL) {
// 		delete this->root;
// 		this->root = NULL;
// 	} else if (this->left_subtree() == NULL) {
// 		bt_node* temp = this->root;
// 		this->root = dynamic_cast<BST<T, K>*>(this->right_subtree())->root;
// 		temp->left=temp->right=NULL;
// 		delete temp;
// 		temp = NULL;
// 		//The problem is in the this->root->value
// 		// cout << this->root->key << "1111" << endl;
// 		// cout << this->root->value << "2222" << endl;
// 		// cout << (this->root->left == NULL ? "NULL" : "Not NULL") << "3333" << endl;
// 		// cout << (this->root->right == NULL ? "NULL" : "Not NULL") << "4444" << endl;
// 	} else if (this->right_subtree() == NULL) {
// 		bt_node* temp = this->root;
// 		this->root = dynamic_cast<BST<T, K>*>(this->left_subtree())->root;
// 		temp->left=temp->right=NULL;
// 		delete temp;
// 		temp = NULL;
// 	} else {
// 		BST<T, K>* right_min = dynamic_cast<BST<T, K>*>(this->right_subtree()->find_min());
// 		// cout << "!!!!" << right_min->root->key << endl;
// 		this->root = right_min->root;
// 		this->right_subtree()->remove(k);
// 	}
// }


template <typename T, typename K>
void BST<T, K>::remove(const K& k)
{
	if (this->is_empty())
		return;
	BST<T, K>* temp = dynamic_cast<BST<T, K>*>(this->search(k));
	if (temp->left_subtree() == NULL && temp->right_subtree() == NULL) {
		delete temp->root;
		temp->root = NULL;
	} else if (temp->left_subtree() == NULL) {
		bt_node* temp_node = temp->root;
		temp->root = dynamic_cast<BST<T, K>*>(temp->right_subtree())->root;
		temp_node->left = temp_node->right = NULL;
		delete temp_node;
		temp_node = NULL;
	} else if (temp->right_subtree() == NULL) {
		bt_node* temp_node = temp->root;
		temp->root = dynamic_cast<BST<T, K>*>(temp->left_subtree())->root;
		temp_node->left = temp_node->right = NULL;
		delete temp_node;
		temp_node = NULL;
	} else {
		BST<T, K>* right_min = dynamic_cast<BST<T, K>*>(temp->right_subtree()->find_min());
		temp->root->value = right_min->root->value;
		temp->root->key = right_min->root->key;
		temp->root->bt_height = right_min->root->bt_height;
		temp->right_subtree()->remove(temp->root->key);
	}
}

/* TODO:
 * Clear the node stack and set current pointer to the root
 */
template<typename T, typename K>
void BST<T, K>::iterator_init()
{
	while (!this->istack.empty()) {
		this->istack.pop();
	}
	this->current = this->root;
}

/* TODO:
 * Check whether the next smallest node exists
 */
template<typename T, typename K>
bool BST<T, K>::iterator_end()
{
	return (this->istack.empty() && this->current == NULL);
}

/* TODO:
 * Return the value of next smallest node from the tree
 */
//This is similar to preorder transverse
template<typename T, typename K>
inline T& BST<T, K>::iterator_next()
{
	while (this->current != NULL && (this->istack.empty()||this->current != this->istack.top())) {
		this->istack.push(this->current);
		if (this->current->left==NULL){
			this->current=NULL;
			break;
		}
		this->current = dynamic_cast<BST<T,K>*>(this->current->left)->root;
	}    
	this->current = this->istack.empty()?NULL:this->istack.top();
	this->istack.pop();
	bt_node* temp = this->current;
	this->current = this->current->right?dynamic_cast<BST<T,K>*>(this->current->right)->root:NULL;


	//This is to ensure the right node has children
	while (this->current != NULL && (this->istack.empty()||this->current != this->istack.top())) {
		this->istack.push(this->current);
		if (this->current->left==NULL){
			this->current=NULL;
			break;
		}
		this->current = dynamic_cast<BST<T,K>*>(this->current->left)->root;
	}
	//Special Attention!! Need to set the this->current
	//to a valid location
	if (this->current == NULL) {
		this->current = this->istack.empty()?NULL:this->istack.top();
		// this->istack.pop();
	}

	//Testing line
	// cout << "Using iterator_next once!" <<endl;
	return temp->value;
}



#endif /* BST_CPP */
