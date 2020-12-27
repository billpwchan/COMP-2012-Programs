#include "person.h"     /* File: family.cpp */

int main()
{
    Person arthur("Arthur", 65, NULL, NULL, NULL);
    Person becky("Becky", 63, NULL, NULL, NULL);
    Person claire("Claire", 32, &arthur, &becky, NULL);
    Person eddy("Eddy", 4, NULL, &claire, NULL);

    arthur.have_child(&claire);
    becky.have_child(&claire);
    claire.have_child(&eddy);

    arthur.print_family(); cout << endl;
    becky.print_family(); cout << endl; 
    claire.print_family(); cout << endl; 
    eddy.print_family(); cout << endl; 
    return 0;
}
