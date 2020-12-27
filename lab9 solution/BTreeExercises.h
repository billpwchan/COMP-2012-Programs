//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

template<class T>
int treeHeight(BtreeNode<T> *root);

template<class T>
int countNodes(BtreeNode<T> *root);

template<class T>
void printLevelOrder(BtreeNode<T> *root);

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root);

template<class T>
bool isComplete(BtreeNode<T> *root);

// Mirror
template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root) {
    if (root == NULL)
        return NULL;

    else {
        BtreeNode<T> *newNode = new BtreeNode<T>(root->get_data(), mirror(root->get_right()),
                                                 mirror(root->get_left()));
        return newNode;
    }
}

// Level Order Traversal
template<class T>
void levelOrderTraversal(BtreeNode<T> *root, void (*action)(BtreeNode<T> *r)) {
    std::queue<BtreeNode<T> *> q;
    if (root == NULL) return;

    q.push(root);
    while (!q.empty()) {
        BtreeNode<T> *node = q.front();
        action(node);
        q.pop();
        if (node->get_left() != NULL)
            q.push(node->get_left());
        if (node->get_right() != NULL)
            q.push(node->get_right());
    }
}

template<class T>
void printNode(BtreeNode<T> *root) {
    std::cout << root->get_data() << " ";
}

template<class T>
void printLevelOrder(BtreeNode<T> *root) {
    levelOrderTraversal(root, &printNode);
}

// Tree Height
template<class T>
int treeHeight(BtreeNode<T> *root) {
    if (root == NULL) return -1;
    int leftHeight = treeHeight(root->get_left());
    int rightHeight = treeHeight(root->get_right());
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// Count Nodes
template<class T>
int countNodes(BtreeNode<T> *root) {
    if (!root) return 0;
    int leftCount = countNodes(root->get_left());
    int rightCount = countNodes(root->get_right());
    return 1 + leftCount + rightCount;
}

// Is Complete
template<class T>
bool isComplete(BtreeNode<T> *root, int index, int nodes_number) {
    if (root == NULL)
        return true;

    if (index >= nodes_number)
        return false;

    return (isComplete(root->get_left(), index * 2 + 1, nodes_number) &&
            isComplete(root->get_right(), index * 2 + 2, nodes_number));
}

template<class T>
bool isComplete(BtreeNode<T> *root) {
    int node_number = countNodes(root);
    return isComplete(root, 0, node_number);
}

#endif //LAB9_BTREEEXERCISES_H
