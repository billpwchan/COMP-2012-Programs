void Stack::push(Stack* this, int x)
{
    if (!this->full())
        this->data[++(this->top_index)] = x; 
}
