#include <iostream>     /* File: const-char-ptrs2.cpp */
using namespace std;

int main()
{
    char s[] = "COMP2012";
    char p[] = "MATH1013";

    const char* pcc = s;   // Pointer to constant char
    pcc[5] = '5';          // Error!
    pcc = p;               // OK, but what does that mean?

    char *const cpc = s;   // Constant pointer
    cpc[5] = '5';          // OK
    cpc = p;               // Error!

    const char *const cpcc = s; // const pointer to const char
    cpcc[5] = '5';         // Error!
    cpcc = p;              // Error!
}
