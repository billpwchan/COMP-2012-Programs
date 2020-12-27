#include <iostream>     /* File: array-int-stack.h */
using namespace std;
const int BUFFER_SIZE = 1000;

class Stack
{
  private:
    int data[BUFFER_SIZE]; // Use an array to store data
    int top_index;         // Starts from 0; -1 when empty

  public:
    // CONSTRUCTOR member functions
    Stack();               // Default constructor

    // ACCESSOR member functions: const => won't modify data members
    bool empty() const;    // Check if the stack is empty
    bool full() const;     // Check if the stack is full
    int size() const;      // Give the number of data currently stored
    int top() const;       // Retrieve the value of the top item
         
    // MUTATOR member functions
    void push(int);        // Add a new item to the top of the stack
    void pop();            // Remove the top item from the stack
};
