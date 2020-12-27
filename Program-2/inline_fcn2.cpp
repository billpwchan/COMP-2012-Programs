class Stack
{ 
    ...
    inline void push(int x) { if (!full()) data[++top_index] = x; }
    inline void pop() { if (!empty()) --top_index; }
};
