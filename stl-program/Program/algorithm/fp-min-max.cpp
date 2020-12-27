#include <iostream>     /* File: fp-min-max.cpp */
using namespace std;

int my_max(int x, int y) { return (x > y) ? x : y; }
int my_min(int x, int y) { return (x > y) ? y : x; }

int main()
{
    int choice;
    cout << "Choice: (1 for my_max; others for my_min): ";
    cin >> choice;

    int (*f)(int x, int y);
    f  = (choice == 1) ? my_max : my_min;

    cout << f(3, 5) << endl;
    return 0;
}

    

    
