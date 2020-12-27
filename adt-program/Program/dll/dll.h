template <typename T>      /* File: dll.h */
class Dll                  // A sorted doubly linked list
{
  private:
    #include "dll-node.h"  // Dll_node for internal use only
    #include "dll-search.h" // Private helper function
    Dll(Dll_node* node_p) : head(node_p) { } // Private constructor!
    Dll_node* head;        // The first Dll_node is the DLL head

  public:
    Dll() : head(0) { }    // Default constructor
    ~Dll();                // Need to release owned objects
    
    int size() const;
    void print() const;
    bool contains(const T& x) const;

    void insert(const T&); // Insert while keeping nodes sorted
    void remove(const T&);
};

