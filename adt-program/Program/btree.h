#include <iostream>        /* File: btree.h */
using namespace std;
template <typename T>
class btree
{
  private:
    struct btree_node      // A node in a binary tree
    {
        T data;
        btree_node* left;  // Left sub-tree or called left child
        btree_node* right; // Right sub-tree or called right child
        btree_node(const T& x) : data(x), left(0), right(0) { };
    };

    btree_node* root;
    
  public:
    btree() : root(0) { }
    ~btree();

    bool is_empty() const { return root == 0; }
    bool contains(const T&) const;
    void print(ostream& os = cout) const;
    void insert(const T&); // Insert an item with a policy
    void remove(const T&); // Remove an item 
};


