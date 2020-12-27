template <typename T>   /* File: dll-destructor.h */
Dll<T>::~Dll()          // To delete the WHOLE linked list
{
    if (head == 0)      // An empty list; nothing to delete
        return;

    // STEP 1: Delete all nodes beyond the head by creating a
    //         temp DLL in a block. How does it work? Recursion!
    {
        Dll remaining_nodes(head->next);
    }

    // For debugging only: this shows what you are deleting
    cout << "deleting " << head->data << endl;
    delete head;        // STEP 2: Then delete the first node

    head = 0;           // STEP 3: Play safe; reset head to NULL
}
