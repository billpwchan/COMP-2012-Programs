#include <iostream>     /* File: misc-namespace.cpp */
using namespace std;

namespace hkust
{
    void good() { cout << "Good!" << endl; }

    namespace cse { int rank() { return 1; } } // Nested namespace
}

namespace hkust { void school() { cout << "School!" << endl; } }

int main()
{ 
    using namespace hkust;
    cout << "CSE's rank: " << cse::rank() << endl;
    good(); school(); return 0;
}
