template <typename T>   /* File: dll-insert.h */
void Dll<T>::insert(const T& x)
{   
    // Insert data in ascending order. The data type must support operator>
    Dll_node* p;
    Dll_node* new_node = new Dll_node(x); // STEP 1: Create the new node   

    if (head == 0) { head = new_node; return; } // Insert at the beginning

    // STEP 2: Find the node before which the new node is to be added
    for (p = head; x > p->data && p->next != 0; p = p->next)
         ;

    // STEP 3: Insert the new node between the found node and its previous node
    if (x > p->data) {  // Then (p->next == 0) and insert at the back
        new_node->prev = p; p->next = new_node;
    }
    else if (p == head) {  // Insert at the front
        new_node->next = p; p->prev = new_node; head = new_node;
    }
    else {  // General case
        new_node->next = p; new_node->prev = p->prev;
        p->prev->next = new_node; p->prev = new_node;
    }
}
