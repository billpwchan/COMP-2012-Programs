/* File: stack1.h */
class Stack
{   
    ...
    inline void pop() 
    {
        if (!empty()) 
            --top_index; 
    }
};
