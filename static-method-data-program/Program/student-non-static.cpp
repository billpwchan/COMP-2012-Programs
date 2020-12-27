#include "student-non-static.h" /* File: student-non-static.cpp */

void Student::do_exam()
{
    if (memory.empty()) 
        cout << name << ": "<< "Huh???" << endl;
    else 
    {
        vector<string>::const_iterator p;

        for (p = memory.begin(); p != memory.end(); ++p)
    	    cout << name << ": " << *p << endl;
    }

    cout << endl;
}
