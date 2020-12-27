//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

using namespace std;

template<class T>
int treeHeight(BtreeNode<T> *root) {
	if (root == NULL)
		return 0;
	else{
		/* compute the depth of each subtree */
		int lDepth = treeHeight(root->get_left());
		int rDepth = treeHeight(root->get_right());

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else return (rDepth + 1);
	}
}

template<class T>
int countNodes(BtreeNode<T> *root) {
	if (root == NULL) {
		return 0;
	}
	return 1+countNodes(root->get_left()) + countNodes(root->get_right());
}

template<class T>
void printLevelOrder(BtreeNode<T> *root) {
	int height = treeHeight(root);
	for (int i = 0; i < height; i++) {
		printGivenLevel(root, i);
	}
}

template<class T>
void printGivenLevel(BtreeNode<T> *root, int level) {
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->get_data();
	else if (level > 1) {
		printGivenLevel(root->get_left(), level - 1);
		printGivenLevel(root->get_right(), level - 1);
	}
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){
	if (root == NULL)
		return NULL;
	else{
		 BtreeNode<T>* temp;
		 mirror(root->get_left());
		 mirror(root->get_right());

		 temp = root->get_left();
		 *(root->get_left())= *(root->get_right());
		 *(root->get_right()) = *temp;
	}
	return root;
}

// template<class T>
// bool isComplete(BtreeNode<T> *root);

#endif //LAB9_BTREEEXERCISES_H
