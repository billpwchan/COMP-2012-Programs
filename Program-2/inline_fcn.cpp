class Stack
{ 
    ...
    void push(int x) { if (!full()) data[++top_index] = x; }
    void pop() { if (!empty()) --top_index; }
};
