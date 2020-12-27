#include <iostream>     /* File: avl-test.cpp */
using namespace std;
#include "avl.h"
#include "avl.cpp"

int main()
{
    AVL<int> avl_tree;
    while(true)
    {
        char choice; int value;
        cout << "Action: e/f/i/n/p/r (end/find/insert/min/print/remove): ";
        cin >> choice;

        switch(choice)
        {
            case 'e': default:
                return 0;

            case 'f':
                cout << "Value to find: "; cin >> value;
                cout << boolalpha << avl_tree.contains(value) << endl;
                break;
            case 'i':
                cout << "Value to insert: "; cin >> value;
                avl_tree.insert(value);
                break;

            case 'n':
                if (avl_tree.empty())
                    cerr << "Can't search an empty tree!" << endl;
                else
                    cout << avl_tree.find_min() << endl;
                break;

            case 'p':
                avl_tree.print();
                break;

            case 'r':
                cout << "Value to remove: "; cin >> value;
                avl_tree.remove(value);
                break;
        }
    }
}
