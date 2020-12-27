/* File: utils-namespace.cpp */
#include "ms-utils-namespace.h"
#include "apple-utils-namespace.h"  

namespace ms = microsoft; // Namespace alias
enum OS { MSWindows, MacOS } choice;

int main() 
{
    apple::Some_Class sc; apple::Stack apple_stack; 
    ms::Other_Class oc; ms::Stack ms_stack;
    int i = ms::func(42);

    if (choice == MacOS)
        apple::safari();
    else if (choice == MSWindows)
        ms::edge();
    return 0;
}
