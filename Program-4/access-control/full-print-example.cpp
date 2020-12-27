/* File: print-example.cpp (incomplete) */
#include <string>
using namespace std;
#include "../basics/student.h"
#include "../basics/teacher.h"

int main( )
{
    UPerson mouse("Mickey", CIVL);
    Teacher einstein("Einstein", CSE, DEAN, "AI");
    Student plato("Plato", ECE, 2.5);
    plato.enroll_course("COMP2012");

    mouse.print( );
    einstein.print( );
    plato.print( );
    return 0;
}
