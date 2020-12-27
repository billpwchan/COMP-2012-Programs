#include "apple-utils.h" /* File: use-utils.cpp */
#include "ms-utils.h"
enum OS { MSWindows, MacOS } choice;

int main() 
{
    Some_Class sc;
    Other_Class oc;
    
    if (choice == MacOS)
        safari();
    else if (choice == MSWindows)
        edge();
    return 0;
}
