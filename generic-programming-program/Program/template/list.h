#include "listnode.h"            /* File: list.h */
template <typename T> class List // A doubly linked list
{
  public:
    List() : head(0), tail(0) { }
    void append(const T& item) {
        List_Node<T>* new_node = new List_Node<T>(item);
        if (!tail)
            head = tail = new_node;
        else
        { /* incomplete */ }
    }
    void print() const {
        for (const List_Node<T>* p = head; p; p = p->next)
            cout << p->data << endl;
    }
    // ... Other member functions
  private:
    List_Node<T>* head;
    List_Node<T>* tail;
};
