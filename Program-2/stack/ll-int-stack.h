#include <iostream>     /* File: ll-int-stack.h */
using namespace std;

struct ll_inode
{
    int data;
    ll_inode* next;
};

class Stack
{
  private:
    ll_inode* head;     // head of a linked list of int's
  public:
    // CONSTRUCTOR member functions
    Stack(); // Default constructor
    // ACCESSOR member functions: const => won't modify data members
    bool empty() const; // Check if the stack is empty
    bool full() const;  // Check if the stack is full
    int size() const;   // Give the number of data currently stored
    int top() const;    // Retrieve the value of the top item
    // MUTATOR member functions
    void push(int);     // Add a new item to the top of the stack
    void pop();         // Remove the top item from the stack
};
