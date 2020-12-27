#include <iostream> /* File: Stack.cpp */

          /***** Default CONSTRUCTOR member function *****/

template <typename T>
Stack<T>::Stack(void) : top_index(-1), data() { } // Create an empty Stack

          /***** ACCESSOR member functions *****/
// Check if the Stack is empty
template <typename T>
bool Stack<T>::empty(void) const { return (top_index == -1); }

// Give the number of data currently stored
template <typename T>
int Stack<T>::size(void) const { return top_index+1; }

// Retrieve the value of the top item
template <typename T>
const T& Stack<T>::top(void) const
{
    if ( !empty() )
        return data[top_index];

    cerr << "Warning: Stack is empty; can't retrieve any data!\n";
    exit(-1);
}

template <typename T>
T& Stack<T>::top(void)
{
    if ( !empty() )
        return data[top_index];

    cerr << "Warning: Stack is empty; can't retrieve any data!\n";
    exit(-1);
}

        /***** MUTATOR member functions *****/
template <typename T>
void Stack<T>::push(const T& x) // Add a new item to the top of the Stack
{
    data.push_back(x);
    ++top_index;
}

template <typename T>
void Stack<T>::pop(void) // Remove the top item from the Stack
{
    if ( !empty() )
    {
        data.pop_back();
        --top_index;
    }
    else
    {
        cerr << "Error: Stack is empty; can't remove any data!\n";
        exit(-1);
    }
}
