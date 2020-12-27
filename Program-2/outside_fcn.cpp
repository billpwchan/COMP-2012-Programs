/* File: stack.h */
class Stack
{   
    ...
    void push(int x);
    void pop();
};

/* File: stack.cpp */
void Stack::push(int x) { if (!full()) data[++top_index] = x; }
void Stack::pop() { if (!empty()) --top_index; }
