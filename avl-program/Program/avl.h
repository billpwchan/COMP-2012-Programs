template <typename T>        /* File: avl.h */
class AVL
{
  private:
    struct AVL_node
    {
        T value;
        int height;
        AVL left;            //  The left subtree object
        AVL right;           // The right subtree object
        AVL_node(const T& x) : value(x), height(0), left(), right() { }
    };

    AVL_node* root;

    AVL& right_subtree() { return root->right; }
    AVL& left_subtree() { return root->left; }
    const AVL& right_subtree() const { return root->right; }
    const AVL& left_subtree() const { return root->left; }

    int height() const;      // Find the height of tree
    int bfactor() const;     // Find the balance factor of tree
    void fix_height() const; // Rectify the height of each node in tree
    void rotate_left();      // Single left or anti-clockwise rotation
    void rotate_right();     // Single right or clockwise rotation
    void balance();          // AVL tree balancing
    
  public:
    AVL() : root(NULL) { }   // Build an empty AVL tree by default
    ~AVL() { delete root; }  // Will delete the whole tree!

    bool empty() const { return root == NULL; }
    const T& find_min() const;       // Find the minimum value in an AVL
    bool contains(const T& x) const; // Search an item
    void print(int depth = 0) const; // Print by rotating -90 degrees
    
    void insert(const T& x); // Insert an item in sorted order
    void remove(const T& x); // Remove an item
};
