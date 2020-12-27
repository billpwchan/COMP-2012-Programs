#include <iostream>     /* File: sll.h */
using namespace std;
template <typename T>
class Sll {
  private:
    struct Sll_node {   // Private, can't be used outside the Sll class
        T data;         // Contains useful information
        Sll_node* next; // The link to the next node
        Sll_node(const T& x): data(x), next(0) { }
    };
    
    Sll_node* head;
    
  public: // The public interface can't use the private type, Sll_node
    Sll() : head(0) { }
    ~Sll();
    
    int size() const;
    bool is_empty() const { return head == 0; }
    void print(ostream& os = cout) const;
    T* ll_search(const T&) const;
    void insert(const T&);
};
