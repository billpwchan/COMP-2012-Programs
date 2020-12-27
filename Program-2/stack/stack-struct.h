const int BUFFER_SIZE = 1000; /* File: stack-struct.h */

struct Stack
{
    int data[BUFFER_SIZE]; // Use an array to store data
    int top_index;         // Starts from 0; -1 when empty

    Stack();               // Default constructor
    bool empty() const;    // Check if the stack is empty
    bool full() const;     // Check if the stack is full
    int size() const;      // Give the number of data currently stored
    int top() const;       // Retrieve the value of the top item
    void push(int);        // Add a new item to the top of the stack
    void pop();            // Remove the top item from the stack
};
