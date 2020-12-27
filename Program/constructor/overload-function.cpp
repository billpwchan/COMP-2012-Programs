#include <iostream>     /* File: overload-function.cpp */
using namespace std;

class Word
{
  private:
    int frequency; char* str; 
  public:
    void set() const { cout << str; }	// Bad overloading! Obscure!
    void set(int k) { frequency = k; }
    void set(char c) { str = new char [2]; str[0] = c; str[1] = '\0'; }
    void set(const char* s) { str = new char [strlen(s)+1]; strcpy(str, s); }
};

int main() 
{ 
    Word movie;         // Which constructor?
    movie.set();        // Which set function?
}
