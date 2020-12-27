template <typename T>   /* File: dll-remove.h */
void Dll<T>::remove(const T& x)
{
    // STEP 1: Find the item to be deleted
    Dll_node* p = search(x);
    
    if (p != 0)         // Delete only if the data is found
    {   // STEP 2: Bypass the found item
        if (p == head)  // Special case: delete the first item
            head = p->next;
        else
            (p->prev)->next = p->next;
        
        if (p->next)    // Special case: not the last item
            (p->next)->prev = p->prev;

        delete p;       // STEP 3: Free memory of the deleted item
    }
    else
        cout << "remove(): " << x << " is not there\n";
}
