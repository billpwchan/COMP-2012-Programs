class Stack             /* File: access_control.cpp */
{
  private:
    int data[BUFFER_SIZE]; 
    int top_index; 
  public:
    void push(int);
    ...
};

int main()
{
    Stack x;
    x.push(2);           // OK: push( ) is public
    cout << x.top_index; // Error: cannot access top_index
    return 0;
}
