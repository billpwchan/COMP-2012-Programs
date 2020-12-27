#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    vector<int>::iterator p;
    p=v.begin();
    cout << "First Element: " << *p << endl;

    p=v.end(); 
    //This .end() function will return the address after the last element
    cout << "Last element: " << *(p-1) << endl;

    for (vector<int>::iterator p1 = v.begin(); p1!=v.end(); p1++){
        cout << "Element: " << *p1 << endl;
    }



}
