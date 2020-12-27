/* File: stack2.h */
class Stack
{   
    ...
    inline void pop();
};

inline void Stack::pop()
{
    if (!empty()) --top_index; 
}
