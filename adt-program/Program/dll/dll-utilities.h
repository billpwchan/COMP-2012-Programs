template <typename T>   /* File: dll-utilities.h */
int Dll<T>::size() const
{
    int length = 0;
    for (const Dll_node* p = head; p != 0; p = p->next)
        ++length;
    return length;
}

template <typename T> 
void Dll<T>::print() const
{
    for (const Dll_node* p = head; p != 0; p = p->next)
        cout << p->data << ' ';
    cout << endl;
}

template <typename T> 
bool Dll<T>::contains(const T& x) const
{
    return search(x) != 0;
}
