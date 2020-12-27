#include "listnode.h"                    /* File: nontype-list.h */
template <typename T, int max_num_items> // A doubly linked list
class List 
{
  public:
    List() : num_items(0), head(0), tail(0) { }
    bool append(const T& item) {
        if (num_items == max_num_items) 
           { cerr << "List is full\n"; return false; }
        else 
           { /* incomplete */ return true; }
    }
    // ... Other member functions
  private:
    int num_items;
    List_Node<T>* head;
    List_Node<T>* tail;
};
