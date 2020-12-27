#include <iostream>     /* File: btree.h */
using namespace std;

template <class T> class Btree_node
{
  public:
    Btree_node(const T& x, Btree_node* L = 0, Btree_node* R = 0)
      : data(x), left(L), right(R) { } 

    ~Btree_node() 
    {
        delete left; delete right;
        cout << "delete the node with data = " << data << endl;
    }

    const T& get_data() const { return data; }
    Btree_node* get_left() { return left; }
    Btree_node* get_right() { return right; }
    
  private:
    T data;             // Stored information
    Btree_node* left;   // Left child
    Btree_node* right;  // Right child
};
