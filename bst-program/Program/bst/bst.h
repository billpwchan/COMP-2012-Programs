template <typename T> class BST /* File: bst.h */
{
  private:
    struct bst_node     // A node in a binary search tree
    {
        T value;
        BST left;       // Left sub-tree or called left child
        BST right;      // Right sub-tree or called right child
        bst_node(const T& x) : value(x), left(), right() { };
    };

    bst_node* root;
    
  public:
    BST() : root(NULL) { }     // Empty BST when its root is NULL
    BST(const BST& bst) { root = bst.root; } // Shallow BST copy

    ~BST() { delete root; }

    bool is_empty() const { return root == NULL; }
    bool contains(const T& x) const;
    void print(int depth = 0) const;
    const T& find_max() const; // Find the maximum value
    const T& find_min() const; // Find the minimum value

    void insert(const T&);     // Insert an item with a policy
    void remove(const T&);     // Remove an item 
};
