class Word    /* File: conversion-constructor-default-arg.cpp */
{
  private:
    int frequency; char* str;
  public:
    Word(const char* s, int k = 1) // Still conversion constructor!
    {
    	frequency = k;
        str = new char [strlen(s)+1]; strcpy(str, s);
    }
};

int main()
{
    Word *p = new Word("action");    // Explicit conversion
    Word movie("Titanic");           // Explicit conversion
    Word director = "James Cameron"; // Implicit conversion
}
