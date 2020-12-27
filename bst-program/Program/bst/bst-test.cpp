#include <iostream>     /* File: bst-test.cpp */
using namespace std;
#include "bst.h"
#include "bst.cpp"

int main()
{
    BST<int> btree;
    while (true)
    {
        char choice; int value;
        cout << "Action: e/f/i/n/p/r/x "
             << "(end/find/insert/min/print/remove/max): ";
        cin >> choice;

        switch (choice)
        {
            case 'e':
                return 0; 

            case 'f':
                cout << "Value to find: "; cin >> value;
                cout << boolalpha << btree.contains(value) << endl;
                break;

            case 'i':
                cout << "Value to insert: "; cin >> value;
                btree.insert(value);
                break;

            case 'n':
                if (btree.is_empty()) 
                    cerr << "Can't search an empty tree!" << endl;
                else
                    cout << btree.find_min() << endl; 
                break;

            case 'p':
            default:
                cout << endl;
                btree.print(); 
                break;
                
            case 'r':
                cout << "Value to remove: "; cin >> value;
                btree.remove(value); 
                break;

            case 'x':
                if (btree.is_empty()) 
                    cerr << "Can't search an empty tree!" << endl;
                else
                    cout << btree.find_max() << endl; 
                break;
        }
    }
}
