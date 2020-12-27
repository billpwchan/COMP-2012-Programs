#include <iostream>     /* File: person-test.cpp */
#include "person.h"

int main()
{
    new Person("Alan");
    new Person("Brian");
    new Person("Cindy");
    new Person("Debbie");

    for (const Person* p = Person::head; p; p = p->get_next())
        cout << p->get_name() << endl;
    
    return 0;
} // Compile: g++ person.cpp person-test.cpp
