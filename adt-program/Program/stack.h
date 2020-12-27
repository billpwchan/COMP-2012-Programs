#include <vector>        /* File: stack.h */

template <typename T>
class Stack
{
  public:
    Stack();             // Default CONSTRUCTOR 

    bool empty() const;  // Check if the stack is empty
    int size() const;    // Give the number of data currently stored
    T& top();            // Retrieve the top item for non-const Stack
    const T& top() const;// Retrieve the top item for const Stack

    void push(const T&); // Add a new item to the top of the stack
    void pop();          // Remove the top item from the stack

  private:
    vector<T> data;      // Array-based implementation
    int top_index;       // Start from 0; -1 when empty
};
