// The returned pointer points to a modifiable Dll_node
Dll_node* search(const T& y) const /* File: dll-search.h */
{
    for (Dll_node* p = head; p != 0; p = p->next)
    {
        if (p->data == y)
            return p;
    }

    return 0;           // Not found!
}
