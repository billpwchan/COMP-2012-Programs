#include "apple-utils-namespace.h" /* File: utils-using.cpp */
#include "ms-utils-namespace.h"
namespace ms = microsoft; // Namespace alias
using apple::Some_Class;
using ms::Other_Class;
using apple::Stack;
using ms::func;

int main() 
{
    Some_Class sc;        // Refer to apple::Some_Class
    Other_Class oc;       // Refer to ms::Other_Class
    Stack apple_stack;    // Refer to apple::Stack
    ms::Stack ms_stack;

    int i = func(2);      // Refer to ms::func
    return 0;
}
