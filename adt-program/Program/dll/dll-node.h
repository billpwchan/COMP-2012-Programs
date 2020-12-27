struct Dll_node         /* File: dll-node.h */
{
    T data;             // Contain useful information
    Dll_node* prev;     // Link to the previous Dll_node in a DLL
    Dll_node* next;     // Link to the next Dll_node in a DLL

    Dll_node(const T& x) : data(x), prev(0), next(0) { };
};
