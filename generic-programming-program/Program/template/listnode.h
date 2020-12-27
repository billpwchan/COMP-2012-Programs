template <typename T>   /* File: listnode.h */
class List_Node
{
  public:
    List_Node(const T& x) : data(x), next(0), prev(0) { }

    List_Node* next;
    List_Node* prev;
    T data;
};

