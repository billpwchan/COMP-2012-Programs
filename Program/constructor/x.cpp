#include <iostream>
class Word 
{
  private:
    int frequency;
    char* str; 
  public:
    Word( ) { frequency = 0; str = 0; } // Default constructor
    void set( ) const { std::cout << str; }	// Bad overloading! Obscure understanding
    void set(int k) { frequency = k; }
    void set(char c) {  str = new char [2]; str[0] = c; str[1] = '\0'; }
    void set(const char* s) { str = new char [strlen(s)+1]; strcpy(str, s); }
};

int main( ) 
{ 
    Word movie; 
    movie.set();
    const Word x;
    x.set(10);
}
